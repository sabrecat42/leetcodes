#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// #define PRINT_STATE() do {                                  \
//     printf("is_number=%d\n", is_number);                   \
//     printf("is_signed=%d\n", is_signed);                   \
//     printf("is_leading=%d\n", leading_zero);               \
//     printf("digits=%d\n", digits);                         \
//     printf("res=%d\n\n", get_num_from_ll(ll, digits));     \
// } while (0)

#define PRINT_STATE() do {                                  \
    printf("is_number=%d\n", is_number);                   \
    printf("is_signed=%d\n", is_signed);                   \
    printf("is_leading=%d\n", leading_zero);               \
    printf("digits=%d\n", digits);                         \
} while (0)

typedef struct linkedList {
    int val;
    struct linkedList* next;
} linkedList;

linkedList* init_ll() {
    linkedList* dummy = malloc(sizeof(linkedList));
    dummy->val=0;
    dummy->next=NULL;
    return dummy;
}

unsigned int pow_int(int a, int b) {
    int res = 1;
    while (b>0) { res = res * a; b--; }
    return res;
}

void add_to_ll(linkedList* l, int val) {
    if (val<0 || val>9) fprintf(stderr, "ERROR: non digit add to ll\n");

    linkedList* to_add = malloc(sizeof(linkedList));
    to_add->val = val;
    to_add->next = NULL;

    linkedList* last_node = l;
    linkedList* next = last_node->next;
    while (next) {
        last_node=next;
        next=last_node->next;
    }
    last_node->next=to_add;
}

unsigned int get_num_from_ll(linkedList* dummy, int digits) {
    unsigned int res = 0;
    linkedList* current_node = dummy->next;
    do {
        int val = current_node->val;
        printf("v=%d\n", val);
        res += (val * pow_int(10, digits-1));
        current_node = current_node->next;
        digits--;
    } while (current_node);

    return res;
    // printf("res=%d\n", res);
}

int myAtoi(char* s) {
    int s_len = strlen(s);
    // state tracking
    short is_number = 0;
    short is_signed = 0;
    short leading_zero = 0;

    // numbers
    short digits = 0;
    linkedList* ll = init_ll();

    for (size_t i = 0; i < s_len; i++) {
        char c = s[i];
        printf("c=%c\n",c);

        if (leading_zero) {
            if (c=='0') {
                leading_zero=1;
                // continue;
            } else if (c>='1' && c<='9') {
                leading_zero=0;
                add_to_ll(ll, (c-48));
                digits++;
                is_number=1;
                // continue;
            } else {
                break;
            }
        } else if (is_number) {
            if (c>=48 && c<=57) {
                add_to_ll(ll, (c-48));
                digits++;
                // continue;
            } else {
                break;
            }
        } else if (!is_number) {
            if (c=='0') {
                leading_zero=1;
                // continue;
            } else if (c>='1' && c<='9') {
                add_to_ll(ll, c-48);
                is_number=1;
                digits++;
                // continue;
            } else if (c==' ') {
                // continue;
            } else if (c=='-') {
                // accept_space=0;
                is_signed=1;
                leading_zero=1;
                // continue;
            } else if (c=='+') {
                leading_zero=1;
            } else {
                break;
            }
        }
        PRINT_STATE();
    }
    // INT32_MAX
    if (digits) {
        if (digits>10 || (digits==10 && (ll->next)->val>=4)) {    // if out of bounds
            if (is_signed) {
                return INT32_MIN;
            } else {
                return INT32_MAX;
            }
        } else if (!is_signed) {
            if (get_num_from_ll(ll, digits) > INT32_MAX) { 
                return INT32_MAX;
            }
        } else if (is_signed) {
            if (get_num_from_ll(ll, digits)-1 > INT32_MAX) { 
                return INT32_MIN;
            }
        }

        int res = get_num_from_ll(ll, digits);
        if (is_signed) return -(unsigned int)res;
        return res;
    }
    return 0;
}

int main(int argc, char const *argv[]) {
    // linkedList* dummy = malloc(sizeof(linkedList));

    // add_to_ll(dummy, 1);
    // add_to_ll(dummy, 2);
    // add_to_ll(dummy, 3);

    // int res = get_num_from_ll(dummy, 3);
    // printf("get_num=%d\n",res);


    // for (short i = 48; i <= 57; i++)
    // {
    //     printf("char %d, is %c\n", i, (char) i);
    // }
    // printf("<space>=%d",' ');
    // char* s = " -003-4-1";
    // char* s = "-98799999999999999999999";
    char* s = "-2147483648";
    int res = myAtoi(s);
    printf("res=%d\n", res);

    return 0;
}
