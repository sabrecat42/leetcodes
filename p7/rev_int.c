#include <stdio.h>
#include <stdlib.h>

unsigned int pow_int(int a, int b) {
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
    unsigned int u_x = x;
    if (is_signed) u_x = -u_x;

    unsigned int res = 0;
    unsigned int div = u_x;
    int digits = 0;
    do {
        div = div / 10;
        digits++;
    } while (div!=0);
    printf("digits=%d\n\n", digits);
    int* ints = malloc(digits * sizeof(int));

    for (int i = digits-1; i>=0; i--) {
        printf("digit_i=%d\n",i);
        if (((digits-(i+1))>=9) && ((u_x / pow_int(10,i)) % 10)>4) return 0;
        int to_add = ((u_x / pow_int(10,i)) % 10) * pow_int(10,(digits-(i+1)));
        if (to_add > INT32_MAX) return 0;
        if (!is_signed && (res + to_add)>INT32_MAX) {printf("x out of range MAX\n"); return 0; }
        if (is_signed && (res + to_add)>=INT32_MAX) {printf("x out of range MIN\n"); return 0; }
        res += to_add;
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
    // int res = reverse(1534236469);
    int res = reverse(-2147483648);
    printf("res=%d",res);

}