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
    ListNode* sortList(ListNode* head) {
        // 排序问题，少于两个节点就直接返回
        if (!head || !head->next)
            return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *order = dummy;
        while (order->next) {
            // 单链表，用p->next找标定点，这样p在要找的前一个
            // 且这样找不到p会停留在要找的最后一个节点上
            // 因此p起始要在第一个要找的前一个
            ListNode *p = order, *pMin = order;
            while (p->next) {
                if (p->next->val < pMin->next->val)
                    pMin = p;
                p = p->next;
            }
            if (pMin == order) {
                order = order->next;
                continue;
            }
            ListNode *tmp = pMin->next;
            pMin->next = pMin->next->next;
            tmp->next = order->next;
            order->next = tmp;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};