#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* strrev(char* str) {
    size_t str_len = strlen(str);
    char* rev_str = malloc(str_len+1);
    for (size_t i = 0; i < str_len; i++) {
        rev_str[i] = str[str_len-(i+1)];
    }
    rev_str[str_len] = '\0';
    return rev_str;
}

char* longestPalindrome(char* s) {
    int len = strlen(s);
    if (len==0) {
        char* empty_str = malloc(1);
        *empty_str = '\0';
    } else {
        for (int i=len; i > 1; i--) {
            for (int j=0; j <= (len-i); j++) {
                int half_i = i/2;
                if ((i%2)==0) {
                    // char* other_half = malloc(half_i+1);
                    // strncpy(other_half, ((s + j) + half_i), half_i);
                    // other_half[half_i] = '\0';
                    // char* rev_other_half = strrev(other_half);
                    // free(other_half);
                    // if (!(strncmp(s + j, rev_other_half, half_i))) {
                    //     char* palindrome = malloc(i+1);
                    //     strncpy(palindrome, s + j, i);
                    //     palindrome[i] = '\0';
                    //     free(rev_other_half);
                    //     return palindrome;
                    // }
                    // free(rev_other_half);
                    int half_match_rev = 1;
                    for (size_t k=half_i; k>0; k--) {
                        if (s[j+(half_i-k)] != s[j+(half_i+k-1)]) {
                            half_match_rev = 0;
                            break;
                        }
                    }
                    if (half_match_rev) {
                        // s[j+i] = '\n';
                        // return s+j;
                        char* palindrome = malloc(i+1);
                        strncpy(palindrome, s+j, i);
                        palindrome[i]='\0';
                        return palindrome;
                    }
                } else {
                    // char* other_half = malloc(half_i+1);
                    // strncpy(other_half, ((s + j + 1) + half_i), half_i);
                    // other_half[half_i] = '\0';
                    // char* rev_other_half = strrev(other_half);
                    // free(other_half);
                    // if (!(strncmp(s + j, rev_other_half, half_i))) {
                    //     char* palindrome = malloc(i+1);
                    //     strncpy(palindrome, s + j, i);
                    //     palindrome[i] = '\0';
                    //     free(rev_other_half);
                    //     return palindrome;
                    // }
                    // free(rev_other_half);
                    int half_match_rev = 1;
                    for (size_t k = half_i; k>0; k--) {
                        if (s[j+(half_i-k)] != s[j+half_i+k]) {
                            half_match_rev = 0;
                            break;
                        }
                    }
                    if (half_match_rev) {
                        // s[j+1+i] = '\n';
                        // return s+j;
                        char* palindrome = malloc(i+1);
                        strncpy(palindrome, s+j, i);
                        palindrome[i]='\0';
                        return palindrome;
                    }
                }
            }
        }
    }
    char* str = malloc(2);
    *(str) = *s;
    *(str+1) = '\0';
    return str;
}