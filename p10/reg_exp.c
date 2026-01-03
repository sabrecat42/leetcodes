#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// will parse first regex element
bool match_recursive(char* str, char* regex) {
    int s_len = strlen(str);
    int r_len = strlen(regex);

    if (r_len==-1) {
        printf("last char is not . or *");
        if (regex[r_i] == "*" || regex[r_i]== '.') {
            fprintf(stderr, "ERROR invalid last regex char");
        }
        if (s_len==1 && s[0]==regex[])
    } else if (regex[r_i+1] == '*') {
        // when wildcard
        if (regex[r_i]=='.') {
            if (r_len==2 && s_len==1) return true;
            // case when zero chars -> same char 
            int is_repeating_char = 1;
            for (size_t s_i = 0; s_i < s_len; s_i++) {
                printf("str=%s; regex=%s\n", str, regex);
                if ((s_i>0 && str[s_i]!=str[s_i-1])) break;
                if (s_i == s_len) return true;
                if (match_recursive((str+s_i), regex+2)) return true;
            }
        }
    }

    return false;
}

bool isMatch(char* s, char* p) {
    int s_len = strlen(s);
    int r_len = strlen(p);
    char* regex = p;

    return match_recursive(s, p);

    // return true;
}

// for (r_i, r_i < r_len, i++):
    // if (regex[r_i+1] == )

int main() {
    char* str= "abb";
    char* regex= ".*.*";
    printf("%d", isMatch(str,regex));
}