/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2, *dummyHead = new ListNode(-1), *p = dummyHead;
        int carry = 0, num;
        while (p1 || p2 || carry) {
            num = 0;
            if (p1) {
                num += p1->val;
                p1 = p1->next;
            }
            if (p2) {
                num += p2->val;
                p2 = p2->next;
            }
            if (carry)
                num += carry;
            if (num >= 10) {
                num = num % 10;
                carry = 1;
            } else {
                carry = 0;
            }
            p->next = new ListNode(num);
            p = p->next;
        }
        p = dummyHead->next;
        delete dummyHead;
        return p;
    }
};
