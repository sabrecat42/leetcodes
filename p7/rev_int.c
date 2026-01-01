#include <stdio.h>
#include <stdlib.h>

int pow_int(int a, int b) {
    // if (b==0) return 1;
    int res = 1;
    while (b>0) {
        res = res * a;
        b--;
    }
    return res;
}

int reverse(int x){
    printf("x=%d\n",x);
    if (x==0) return 0;
    int is_signed = (x<0);
    printf("is_signed=%d\n",is_signed);
    if (is_signed) x = -x;

    int res = 0;
    int div = x;
    int digits = 0;
    do {
        div = div / 10;
        digits++;
    } while (div!=0);
    printf("digits=%d\n\n", digits);
    int* ints = malloc(digits * sizeof(int));

    for (int i = digits-1; i>=0; i--) {
        printf("digit_i=%d\n",i);
        if (((x / pow_int(10,i)) % 10) * pow_int(10,(digits-(i+1))) > INT32_MAX) return 0;
        int to_add = ((x / pow_int(10,i)) % 10) * pow_int(10,(digits-(i+1)));
        if (!is_signed && (res + to_add)<0) {printf("x out of range MAX\n"); return 0; }
        if (is_signed && -(res + to_add) > 0) {printf("x out of range MIN\n"); return 0; }
        res += ((x / pow_int(10,i)) % 10) * pow_int(10,(digits-(i+1)));
        // printf("pow_int(10,i) mod 10)=%d\n",);
        // x -= (x % pow_int(10,i)) * (pow_int(10,digits-1));
        printf("res=%d\n",res);
        printf("\n");
    }
    if (is_signed) return -res;

    return res;
}

int main() {
    // int res = reverse(-12347899);
    // int res = reverse(1232123123);
    // int res = reverse(2147483647);
    int res = reverse(1534236469);
    printf("res=%d",res);

}