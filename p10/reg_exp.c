#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// will parse first regex element
bool match_recursive(char* str, char* reg) {
    printf("checking for str=%s, reg=%s\n",str,reg);

    // printf("\n");
    int s_len = strlen(str);
    int r_len = strlen(reg);

    
    // if (s_len==2 && str[0]=='b') {
    //     printf("    again: checking for str=%s, reg=%s\n",str,reg);
    // }

    if (r_len==0 && s_len==0) {
        printf("empty reg and str -> true\n");
        return true;
    }

    if (r_len==0 && s_len>0) {
        printf("str=%s; reg=%s -> empty reg and non-empty str -> false\n\n", str, reg);
        return false;
    }

    if (r_len==1) {
        printf("last char is not . or *\n");
        if (reg[0] == '*' || reg[0]== '.') {
            fprintf(stderr, "ERROR: invalid last regex char");
        }
        if (s_len==1 && str[0]==reg[0]) return true;
    } else if (reg[1] == '*') {                 // when star
        printf("    when star\n");
        if (reg[0]=='.') {                              // when wildcard
            if (r_len==2) {
                printf("        .* is last regex elem\n");
                return true;
            }
            // case when zero chars -> same char 

            // for (size_t s_i = 0; s_i < s_len; s_i++) {
            //     printf("doing the check for all chars when star and wild card\n");
            //     if ((s_i>0 && str[s_i]!=str[s_i-1])) break;
            //     if (s_i == s_len-1) return true;
            //     if (s_i==s_len-1 && match_recursive((str+s_i), reg+2)) return true;
            // }
            // when all future regex elements are also .*
            
            // when all future regex elements are also .*
            if (s_len/2==0) {
                for (size_t i = 0; i < s_len/2; i++) {
                    if (reg[i*2]!='.' || reg[i*2+1]!='*') {
                        break;
                    }
                }
                return true;
            }
            for (size_t s_i = 0; s_i < s_len; s_i++) {
                printf("str=%s; regex=%s\n", (str+s_i), reg+2);
                // if (s_i>0 && str[s_i]!=str[s_i-1]) {
                //     printf("star & wild card -> will break\n");
                //     if (match_recursive((str+s_i),reg+2)) return true;
                //     break;
                // }
                // if (s_i == s_len-1) {
                //     printf("star and wilcrad matched till last char.\n");
                //     return true;
                // }
                printf("will do check on str+s_i=%s and reg+2=%s\n\n", (str+s_i), reg+2);
                if (match_recursive((str+s_i), reg+2)) return true;
            }
        } else if (reg[0] != '.' && reg[0] != '*') {    // non-wildcard
            printf("        non-wildcard\n");
            if (r_len==2 && s_len==1 && str[0] == reg[0]) return true;
            // TODO: count until what index str matches .*, and then match_recursive from largest str+i to smallest => more efficient
            for (size_t s_i = 0; s_i < s_len; s_i++) {
                if (s_i==0 && !(str[0] == reg[0])) break;
                if (s_i>0 && str[s_i]!=str[s_i-1]) {
                    printf("star & non-wild card -> will break\n");
                    if (match_recursive((str+s_i),reg+2)) return true;
                    break;
                }
                if (s_i == s_len-1) {
                    printf("star and non-wilcrad matched till last char.\n");
                    return true;
                }
                if (match_recursive((str+s_i), reg+2)) return true;
            }
        } else {
            fprintf(stderr, "ERROR l42: unhandled star case");
        }
    } else {                                    // when no star
        printf("No star\n");
        if (reg[0]=='.') {                              // when wildcard
            printf("    W. wildcard\n");
            if ((r_len==1) && (s_len==0 || s_len==1)) {
                return true;
            } else {
                if (match_recursive(str, reg+1)) return true;
                if (s_len>1 && match_recursive(str+1, reg+1)) return true;
            }
        } else {                                        // when no wildcard
            printf("    No wildcard\n");
            if (reg[0] == str[0]) {
                if (s_len==1 && r_len==1) {
                    return true;
                } else if (s_len>1 && r_len>1) {
                    printf("will match_rec for str+1=%s, reg+1=%s\n",str+1, reg+1);
                    if (match_recursive(str+1, reg+1)) return true;
                } else {
                    fprintf(stderr, "ERROR l82: invalid case");
                }
            }
        }
    }
    printf("returning false\n\n");
    return false;
}

bool isMatch(char* s, char* p) {
    // int s_len = strlen(s);
    // int r_len = strlen(p);
    // char* regex = p;

    return match_recursive(s, p);

    // return true;
}

// for (r_i, r_i < r_len, i++):
    // if (regex[r_i+1] == )

int main() {
    // char* str= "aaabc";  // match
    // char* regex= ".*bc";
    // char* str= "aa";     //not match
    // char* regex= "a";
    // char* str= "aa";     // match
    // char* regex= "a*";
    // char* str= "ab";     // match
    // char* regex= ".*";
    // char* str= "abbcc";     // not match
    // char* regex= ".*bc";
    char* str= "sjskjfsadlfsadfsfffjlaskjdjflkajs";     // not match
    char* regex= ".*skj......sad..ff*jla.*..kajs";
    
    if (isMatch(str,regex)) {
        printf("is match");
    } else {
        printf("not macth");
    }
}