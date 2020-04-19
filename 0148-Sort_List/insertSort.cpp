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
        ListNode *order = dummy->next;
        while (order->next) {
            ListNode *p = dummy;
            while (p->next != order->next && p->next->val <= order->next->val)
                p = p->next;
            if (p == order) {
                order = order->next;
                continue;
            }
            ListNode *tmp = order->next;
            order->next = order->next->next;
            tmp->next = p->next;
            p->next = tmp;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};