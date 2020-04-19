/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* cutN(ListNode *head, int len) {
        if (!head)
            return NULL;
        while (head->next && --len)
            head = head->next;
        ListNode *tmp = head->next;
        head->next = NULL;
        return tmp;
    }
public:
    ListNode* sortList(ListNode* head) {
        // 排序问题，少于两个节点就直接返回
        if (!head || !head->next)
            return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        int sz = 0;
        while (head) {
            head = head->next;
            sz++;
        }
        for (int len = 1; len < sz; len += len) {
            ListNode *pre = dummy;
            ListNode *p = dummy->next;
            while (p) {
                ListNode *l1 = p;
                ListNode *l2 = cutN(l1, len);
                p = cutN(l2, len);
                while (l1 && l2)
                    if (l1->val <= l2->val) {
                        pre->next = l1;
                        pre = pre->next;
                        l1 = l1->next;
                    } else {
                        pre->next = l2;
                        pre = pre->next;
                        l2 = l2->next;
                    }
                pre->next = l1 ? l1 : l2;
                while (pre->next)
                    pre = pre->next;
            }
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};