#include <stdio.h>
#include <stdlib.h>

unsigned int pow_int(int a, int b) {
    int res = 1;
    while (b>0) { res = res * a; b--; }
    return res;
}

int reverse(int x){
    // printf("x=%d\n",x);
    if (x==0) return 0;
    int is_signed = (x<0);
    // printf("is_signed=%d\n",is_signed);
    unsigned int u_x = x;
    if (is_signed) u_x = -u_x;

    unsigned int res = 0;
    unsigned int div = u_x;
    short digits = 0;
    do {
        div = div / 10;
        digits++;
    } while (div!=0);
    // printf("digits=%d\n\n", digits);

    for (int i = digits-1; i>=0; i--) {
        // printf("digit_i=%d\n",i);
        short pow_of_10 = (digits-(i+1));

        if ((pow_of_10>9) || (pow_of_10==9 && ((u_x / pow_int(10,i)) % 10>4))) return 0;
        int to_add = (u_x / pow_int(10,i)) % 10 * pow_int(10,pow_of_10);
        if (to_add > INT32_MAX) return 0;
        res += to_add;
        if ((!is_signed && res>INT32_MAX) || (is_signed && res>=INT32_MAX)) {
            // printf("x out of range MAX\n"); 
            return 0; 
        }
        // printf("res=%d\n",res);
        // printf("\n");
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