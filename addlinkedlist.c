/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//  # include <stdio.h>
//  # include <math.h>
 # include <stdlib.h>

//  Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

int pos_pow(int a, int b) {
    int res = 1;
    while (b>0) {
        res = res * a;
        b--;
    }
    return res;
}

int computeListLength(struct ListNode* l) {
    int len = 0;
    struct ListNode* ll = l;
    while (ll->next) {
        len++;
        ll = ll->next;
    }
    return len;
}

int computeInt(struct ListNode* l, int len) {
    int res = 0;
    struct ListNode* ll = l;
    for (int i=len; i>=0; i--) {
        res += (ll->val) * pos_pow(10,i);
        ll = ll->next;
    }
    return res;
}

struct ListNode* makeLinkedList(int number) {
    int modulo = 10;
    int div = 1;
    
    int is_head = 1;
    struct ListNode* list = NULL;
    struct ListNode* last_list = NULL;
    struct ListNode* head = NULL;
    if (number==0) {
        head = malloc(sizeof(struct ListNode));
        head->val=0;
        head->next=NULL;
    }
    while (number / div != 0) {
        int val = (number % modulo) / div;
        printf("val=%d\n",val);

        list = malloc(sizeof(struct ListNode));
        if (is_head) head = list;
        is_head = 0;

        list->val=val;
        list->next=NULL;
        if (last_list) last_list->next = list;

        last_list = list;
        modulo = modulo * 10;
        div = div * 10;
    }
    return head;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int len1 = computeListLength(l1);
    // printf("len1=%d\n",len1);
    int len2 = computeListLength(l2);
    // printf("len2=%d\n",len2);
    int int1 = computeInt(l1, len1);
    // printf("int1=%d\n",int1);
    int int2 = computeInt(l2, len2);
    // printf("int2=%d\n",int2);
    // printf("%d", int1 + int2);
    return makeLinkedList(int1+int2);
}

int main() {
    addTwoNumbers(makeLinkedList(997990900),makeLinkedList(989982099));
}

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     struct ListNode *next;
//  * };
//  */

//  # include <stdlib.h>

// int pos_pow(int a, int b) {
//     int res = 1;
//     while (b>0) {
//         res = res * a;
//         b--;
//     }
//     return res;
// }

// int computeListLength(struct ListNode* l) {
//     int len = 0;
//     struct ListNode* ll = l;
//     while (ll->next) {
//         len++;
//         ll = ll->next;
//     }
//     return len;
// }

// int computeInt(struct ListNode* l, int len) {
//     int res = 0;
//     struct ListNode* ll = l;
//     for (int i=len; i>=0; i--) {
//         res += (ll->val) * pos_pow(10,i);
//         ll = ll->next;
//     }
//     return res;
// }

// struct ListNode* makeLinkedList(int number) {
//     int modulo = 10;
//     int div = 1;
    
//     int is_head = 1;
//     struct ListNode* list = NULL;
//     struct ListNode* last_list = NULL;
//     struct ListNode* head = NULL;
//     if (number==0) {
//         head = malloc(sizeof(struct ListNode));
//         head->val=0;
//         head->next=NULL;
//     }
//     while (number / div != 0) {
//         int val = (number % modulo) / div;
//         printf("val=%d\n",val);

//         list = malloc(sizeof(struct ListNode));
//         if (is_head) head = list;
//         is_head = 0;

//         list->val=val;
//         list->next=NULL;
//         if (last_list) last_list->next = list;

//         last_list = list;
//         modulo = modulo * 10;
//         div = div * 10;
//     }
//     return head;
// }

// struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
//     int len1 = computeListLength(l1);
//     // printf("len1=%d\n",len1);
//     int len2 = computeListLength(l2);
//     // printf("len2=%d\n",len2);
//     int int1 = computeInt(l1, len1);
//     // printf("int1=%d\n",int1);
//     int int2 = computeInt(l2, len2);
//     // printf("int2=%d\n",int2);
//     // printf("%d", int1 + int2);
//     return makeLinkedList(int1+int2);
// }