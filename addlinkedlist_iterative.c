/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 # include <stdio.h>
 # include <stdlib.h>

//  Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

void printLinkedList(struct ListNode* l) {
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

// struct ListNode* addWithCarry(struct ListNode* l1, struct ListNode* l2, int carry) {
//     if (!l1 && !l2 && !carry) return NULL;

//     int sum = carry;
//     if (l1) sum += l1->val;
//     if (l2) sum += l2->val;

//     struct ListNode* node = malloc(sizeof(struct ListNode));
//     node->val = sum % 10;
//     node->next = addWithCarry(
//         l1 ? l1->next : NULL,
//         l2 ? l2->next : NULL,
//         sum / 10);

//     return node;
// }

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    struct ListNode head = {.val=0, .next=NULL};
    struct ListNode* node = &head;
    while (l1 || l2 || carry) {
        int val = carry;
        if (l1) { val+=l1->val; l1 = l1->next; }
        if (l2) { val+=l2->val; l2 = l2->next; }
        node->next=malloc(sizeof(struct ListNode));
        node = node->next;
        node->val = val%10;
        node->next = NULL;
        carry = val/10;
    }
    return head.next;
}

void addTail(struct ListNode* l1, struct ListNode* l2) {
    while (l1->next) {
        l1 = l1->next;
    }
    l1->next = l2;
}



int main() {
    struct ListNode* l1 = makeLinkedList(10000000000001);
    addTail(l1, makeLinkedList(10000000000001));   
    struct ListNode* l2 = makeLinkedList(456);
    printLinkedList(l1); 
    printLinkedList(l2); 
    struct ListNode* res_list = addTwoNumbers(l1,l2);

    printLinkedList(res_list);
}