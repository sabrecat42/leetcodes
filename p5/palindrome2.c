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

int check_palindrome(int i, int j, char* s, char* longest_palindrome) {
    if (s[i-j] == s[i+j]) return 0;
    if (s[i-j] == s[i+j-1]) {
        if (2*j+1 > strlen(longest_palindrome)) {
            strncpy(longest_palindrome, s+i-j, 2*j+1);
            longest_palindrome[2*j+1] = '\0';
        }
    } else if (s[i+j-1] == s[i+j]) {
        if (2*j+1 > strlen(longest_palindrome)) {
            strncpy(longest_palindrome, s+i-j+1, 2*j+1);
            longest_palindrome[2*j+1] = '\0';
        }
    } else {
        if (2*j > strlen(longest_palindrome)) {
            strncpy(longest_palindrome, s+i-j, 2*j);
            longest_palindrome[2*j] = '\0';
        }
    }
    return 1;
}

char* longestPalindrome(char* s) {
    int len = strlen(s);
    char* longest_palindrome = malloc(1001);
    longest_palindrome[0] = '\0';
    if (len==0) {
        char* empty_str = malloc(1);
        *empty_str = '\0';
        return empty_str;
    } else {
        for (int i=0; i < len; i++) {
            // also need for case when abbra -> bb
            if (i<=(len/2)) {
                for (int j=0; j < i; j++) {
                    if (check_palindrome(i, j, s, longest_palindrome)) break;
                }
            } else {
                for (int j=0; j < (len-i); j++) {
                    if (check_palindrome(i, j, s, longest_palindrome)) break;
                }
            }
        }
    }
    return longest_palindrome;
}

int main() {
    char* s = "baobab";

    char* lp = longestPalindrome(s);
    printf("%s\n",lp);
    return 0;
}