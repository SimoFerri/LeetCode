/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addAtTheEnd(struct ListNode* l, int val) {
    struct ListNode *curr, *tmp;

    tmp = malloc(sizeof(struct ListNode));
    if(tmp) {
        tmp->val = val;
        tmp->next = NULL;
        if(!l) {
            l = tmp;
        } else {
            curr = l;
            while(curr && curr->next) {
                curr = curr->next;
            }
            curr->next = tmp;
        }
    }
    return l;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *curr1, *curr2, *l3 = NULL;
    int n1, n2, n3, i;


    for(i = 1, n1 = 0, curr1 = l1; curr1; curr1 = curr1->next, i *= 10) {
        n1 += curr1->val * i;
    }
    for(i = 1, n2 = 0, curr2 = l2; curr2; curr2 = curr2->next, i *= 10) {
        n2 += curr2->val * i;
    }
    n3 = n1 + n2;
    if(n3 == 0)
        l3 = addAtTheEnd(l3, 0);

    while(n3 > 0) {
        l3 = addAtTheEnd(l3, n3 % 10);
        n3 /= 10;
    }
    return l3;
}