/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 # include <stdio.h>
 # include <stdlib.h>
 # include <stdbool.h>

//  Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

unsigned long long int pos_pow(int a, int b) {
    unsigned long long int res = 1;
    while (b>0) {
        res = res * a;
        b--;
    }
    return res;
}

unsigned long long int computeInt(struct ListNode* l) {
    unsigned long long int res = 0;
    int dec_pos=0;
    do {
        res += l->val * pos_pow(10,dec_pos);
        l=l->next;
        dec_pos++;
    } while (l);
    return res;
}

void printListInt(struct ListNode* l) {
    while (l)
    {
        printf("%d",l->val);
        l = l->next;
    }
    printf("\n");
}

struct ListNode* makeLinkedList(unsigned long long int number) {
    unsigned long long int modulo = 10;
    unsigned long long int div = 1;
    
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
        unsigned long long int val = (number % modulo) / div;
        printf("val=%llu\n",val);

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

// struct ListCarry {
//     struct ListNode* tail;
//     int carry;
// }

struct ListNode* addWithCarry(struct ListNode* l1, struct ListNode* l2, struct ListNode* tail, bool got_carry) {
    // printf("adding %d with %d with carry?=%d\n", l1->val, l2->val, got_carry);

    struct ListNode* node = malloc(sizeof(struct ListNode));
    
    if (!l1 && !l2) {
        if (got_carry) {
            node->val=1;
            node->next=tail;
            return node;
        }
        return tail;
    } else if (!l1) {
        // node->val=l2->val;
        // node->next=l2;
        return l2;
    } else if (!l2) {
        // node->val=l1->val;
        // node->next=l1;
        return l1;
    }

    int sum = (l1->val + l2->val);
    if (got_carry) sum++;
    bool send_carry = sum/10;
    node->val = sum % 10;
    node->next = addWithCarry(l1->next, l2->next, node, send_carry);
    return node;
}

void addTail(struct ListNode* l1, struct ListNode* l2) {
    while (l1->next) {
        l1 = l1->next;
    }
    l1->next = l2;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    return addWithCarry(l1, l2, NULL, false);
}

int main() {
    struct ListNode* l1 = makeLinkedList(10000000000001);
    addTail(l1, makeLinkedList(10000000000001));   
    struct ListNode* l2 = makeLinkedList(465);
    printListInt(l1); 
    printListInt(l2); 
    struct ListNode* res_list = addTwoNumbers(l1,l2);

    printListInt(res_list);
    // printf("%llu", computeInt(res_list));
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