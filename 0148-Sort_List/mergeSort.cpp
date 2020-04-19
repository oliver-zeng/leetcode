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
        // 只有一个或没有节点，就直接返回
        if (!head || !head->next)
            return head;
        // fast,slow 快慢双指针法
        // fast为空，奇数个节点，slow为中间节点
        //   1,   2,   3
        // slow  fast
        //       slow      fast
        // fast->next为空，有偶数个节点，slow为中间偏左节点
        //   1,   2,   3,   4
        // slow  fast
        //       slow      fast
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 从中间拆成[head, slow]与[slow->next, end]左右两段
        ListNode *tmp = slow->next;
        slow->next = NULL;
        // 分别对两段进行排序
        ListNode *left = sortList(head);
        ListNode *right = sortList(tmp);
        // 再对排好序的两段进行归并排序
        // 因为左右子段可能为空，所以需要用到哨兵节点
        ListNode *dummyHead = new ListNode(0), *p = dummyHead;
        while (left && right) {
            if (left->val < right->val) {
                p->next = left;
                left = left->next;
            } else {
                p->next = right;
                right = right->next;
            }
            p = p->next;
        }
        p->next = left ? left : right;
        ListNode *res = dummyHead->next;
        delete dummyHead;
        return res;
    }
};