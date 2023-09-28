#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;

struct ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* ret = malloc(sizeof(ListNode));
    ListNode* r = ret;
    int carry = 0;
    while (l1 != 0 && l2 != 0) {
        ret->val = (l1->val + l2->val + carry) % 10;
        carry = (l1->val + l2->val + carry) / 10;
        ret->next = 0;
        if (!(l1->next == 0 && l2->next == 0)) {
            ret->next = malloc(sizeof(ListNode));
            ret = ret->next;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1 != 0) {
        ret->val = (l1->val + carry) % 10;
        carry = (l1->val + carry) / 10;
        ret->next = 0;
        if (l1->next != 0) {
            ret->next = malloc(sizeof(ListNode));
            ret = ret->next;
        }
        l1 = l1->next;
    }
    while (l2 != 0) {
        ret->val = (l2->val + carry) % 10;
        carry = (l2->val + carry) / 10;
        ret->next = 0;
        if (l2->next != 0) {
            ret->next = malloc(sizeof(ListNode));
            ret = ret->next;
        }
        l2 = l2->next; 
    }
    if (carry != 0) {
        ret->next = malloc(sizeof(ListNode));
        ret = ret->next;
        ret->val = carry;
        ret->next = 0;
    }
    return r;
}