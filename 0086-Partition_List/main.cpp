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
    ListNode* partition(ListNode* head, int x) {
        ListNode *less = new ListNode(0);
        ListNode *pLess = less;
        ListNode *others = new ListNode(0);
        ListNode *pOthers = others;
        ListNode *p = head;
        while(p) {
            if (p->val < x) {
                pLess->next = p;
                pLess = pLess->next;
                p = p->next;
                // 这个必须有，把p接到pLess后，要从原有list断掉
                pLess->next = NULL;
            } else {
                pOthers->next = p;
                pOthers = pOthers->next;
                p = p->next;
                // 这个必须有，把p接到pOthers后，要从原有list断掉
                pOthers->next = NULL;
            }
        }
        pLess->next = others->next;
        head = less->next;
        delete less;
        delete others;
        return head;
    }
};
