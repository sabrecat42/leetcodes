#include <stdbool.h>
#include <stdio.h>

unsigned int pow_int(int a, int b) {
    unsigned int res = 1;
    while (b>0) { res = res * a; b--; }
    return res;
}

bool isPalindrome(int x) {
    if (x<0) return false;
    int digits = 1;
    int div = x;
    while (div/10) {
        printf("%d\n",div/10);
        div = div/10;
        digits++;
    }
    printf("digits=%d\n", digits);

    // bool is_palindrome = true;
    int i = 0;
    while (i<(digits/2)) {
        printf("comparing %d with %d\n",((x/pow_int(10,i))%10), ((x/pow_int(10,((digits-1)-i)))%10));

        if (((x/pow_int(10,i))%10) != ((x/pow_int(10,((digits-1)-i)))%10)) {
            return false;
        }
        i++;
    }

    return true;
}

int main() {
    bool is_p = isPalindrome(10101);
    if (is_p) {
        printf("true"); 
    } else {
        printf("false");
    }
    // printf("%d",isPalindrome(10));
}

// negative -> false
// 