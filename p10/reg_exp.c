#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// will parse first regex element

bool isMatch(char* str, char* reg) {
    printf("checking for str=%s, reg=%s\n",str,reg);

    // printf("\n");
    int str_len = strlen(str);
    int reg_len = strlen(reg);

    
    // if (str_len==2 && str[0]=='b') {
    //     printf("    again: checking for str=%s, reg=%s\n",str,reg);
    // }

    if (str_len>0 && reg_len==0) {
        // printf("non-empty string and empty regex -> false\n");
        return false;
    }

    if (reg_len>=2 && str_len==0 && reg[1]=='*') {
        if (isMatch((str),reg+2)) {
            return true;
        }
    }

    if (reg_len==0 && str_len==0) {
        // printf("empty reg and str -> true\n");
        return true;
    }

    if (reg_len>1 && str_len==0) {
        if (reg_len==2 && reg[1]=='*') {
            // printf("empty str and star reg -> true\n");
            return true;
        } else if (reg[1]!='*') {
            // printf("empty str but first reg elem is not star -> false\n");
            return false;
        }
    }

    if (reg_len==0 && str_len>0) {
        // printf("str=%s; reg=%s -> empty reg and non-empty str -> false\n\n", str, reg);
        return false;
    }

    if (reg_len>=2 && reg[1] == '*') {                 // when star
        // printf("    when star\n");

        // optimization to skip repeating c* e.g. c*c*c*c* -> c*
            // TODO: also optimize when sequence of star elements that contain at elas one .* :
                // e.g. a*b*c*.*a*b* => .*
        if (reg_len>=4) {
            unsigned int add_to_reg = 0;
            bool has_wildcard_star = false;
            if (reg[0]=='.') {
                has_wildcard_star = true;
                for (int i = 1; i < reg_len/2; i++) {
                    if (reg[i*2+1]=='*') {
                        add_to_reg+=2;
                    } else {
                        break;
                    }
                }
            } else {
                for (int i = 1; i < reg_len/2; i++) {
                    if (reg[i*2]=='.' && reg[i*2+1]=='*') has_wildcard_star = true;
                    if ((reg[i*2]==reg[0] || has_wildcard_star) && reg[i*2+1]=='*') {
                        add_to_reg+=2;
                    } else {
                        break;
                    }
                }
            }
            printf("        star->non-wildcard-> optimizing for %d of %c*; reg_len=%d\n",(add_to_reg),reg[0],reg_len);
            reg += add_to_reg;
            if (has_wildcard_star) {
                size_t reg_len = strlen(reg);
                char* new_reg = malloc(sizeof(char)*(reg_len+1));
                strcpy(new_reg, reg);
                new_reg[reg_len]='\0';
                reg = new_reg;
                reg[0] = '.';
                printf("            has_wildcard_star -> created new reg=%s\n",reg);
            }
            reg_len = strlen(reg);
        }

        if (reg[0]=='.') {                              // when wildcard
            // printf("        when wildcard\n");
            if (reg_len==2) {
                // printf("        .* is last regex elem\n");
                return true;
            }

            for (int s_i = str_len; s_i >= 0; s_i--) {
                // printf("will do check on str+s_i=%s and reg+2=%s\n\n", (str+s_i), reg+2);
                if (s_i>str_len) fprintf(stderr, "ERROR: star -> wildcard -> going to str out of bounds\n");
                if (isMatch((str+s_i), reg+2)) return true;
            }

        } else if (reg[0] != '.') {                     // non-wildcard
            // printf("        non-wildcard\n");


            if (reg_len==2 && str_len==1 && str[0] == reg[0]) return true;
            // TODO: count until what index str matches c*, and then isMatch from largest str+i to smallest => more efficient
            int matching_chars = 0;
            for (int s_i = 0; s_i < str_len; s_i++) {
                if (str[s_i]==reg[0]) {
                    matching_chars++;
                } else {
                    break;
                }
            }
            // printf("            matching '%c' = %d\n",reg[0],matching_chars);
            
            for (int s_i = matching_chars; s_i >=0; s_i--) {
                if (s_i>str_len) fprintf(stderr, "ERROR: star -> non-wildcard -> going to str out of bounds\n");
                if (isMatch((str+s_i), reg+2)) return true;
            }
        } else {
            fprintf(stderr, "ERROR l42: unhandled star case");
        }
    } else {                                    // when no star
        // printf("No star\n");
        if (reg[0]=='.') {                              // when wildcard
            // printf("    W. wildcard\n");
            if (str_len==0) {
                // printf("wildcard but empty string -> false\n");
                return false;
            }
            if ((reg_len==1) && (str_len==1)) {
                return true;
            } else {
                if (1>str_len) fprintf(stderr, "ERROR: no star -> wildcard -> going to str out of bounds\n");

                if (isMatch(str+1, reg+1)) return true;
            }
        } else {                                        // when no wildcard
            // printf("    No wildcard\n");
            if (reg[0] == str[0]) {
                if (str_len==1 && reg_len==1) {
                    return true;
                } else if (reg_len>1) {
                    // printf("will match_rec for str+1=%s, reg+1=%s\n",str+1, reg+1);
                    if (1>str_len) fprintf(stderr, "ERROR: no star -> no wildcard -> going to str out of bounds\n");
                    if (isMatch(str+1, reg+1)) return true;
                } else {
                    fprintf(stderr, "ERROR l82: invalid case\n");
                }
            }
        }
    }
    // printf("returning false\n\n");
    return false;
}

// for (r_i, r_i < reg_len, i++):
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
    // char* str= "sjskjfsadlfsadfsfffjlaskjdjflkajs";     // not match
    // char* regex= ".*skj......sad..ff*jla.*..kajs";
    // char* str= "aab";     // match
    // char* regex= "c*a*b";
    // char* str= "mississippi";     // match
    // char* regex= "mis*is*ip*.";
    // char* str= "ppi";     // match
    // char* regex= "p*.";
    // char* str= "a";     // match
    // char* regex= "ab*";
    // char* str= "a";     // false 
    // char* regex= ".*..a*";
    // char* str= "a";     // false
    // char* regex= ".*..";
    // char* str= "acaabbaccbbacaabbbb";     // false
    // char* regex= "a*.*b*.*a*aa*a*";
    // char* str= "aabcbcbcaccbcaabc";     // true
    // char* regex= ".*a*aa*.*b*.c*.*a*";
    // char* str= "abbabaaaaaaacaa";     // true
    // char* regex= "a*.*b.a.*c*b*a*c*";
    // char* str= "aaaaaaaaaaaaaaaaaaab";     // true
    // char* regex= "a*a*a*a*a*a*a*a*a*a*";
    // char* str= "bbbba";     // true
    // char* regex= ".*a*a";
    char* str= "aabcbcbcaccbcaabc";     // true
    char* regex= ".*a*aa*.*b*.c*.*a*";
    
    if (isMatch(str,regex)) {
        printf("is match");
    } else {
        printf("not macth");
    }
}