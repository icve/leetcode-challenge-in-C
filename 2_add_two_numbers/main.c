#include <stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *rlt = malloc(sizeof(struct ListNode));
    struct ListNode *c = rlt;
    struct ListNode *o1 = l1;
    struct ListNode *o2 = l2;
    int v1 = o1->val;
    int v2 = o2->val;
    int carry = 0;
    while (1){
        int sum = v1 + v2 + carry;
        carry = 0;
        if(sum - 10 >= 0){
            carry = 1;
            sum = sum - 10;
        }
        c->val = sum;

        if(!o1->next && !carry){
            c-> next = o2->next;
            return rlt;
        }
        if(!o2->next && !carry){
            c-> next = o1->next;
            return rlt;
        }
        c->next = malloc(sizeof(struct ListNode));
        c = c -> next;
        c->next = NULL;
        if(o1->next){
            o1 = o1->next;
            v1 = o1->val;
        }else{
            v1 = 0;
        }
        if(o2->next){
            o2 = o2->next;
            v2 = o2->val;
        }else{
            v2 = 0;
        }
    }
}


