/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 相关题 LeetCode 86. Partition List
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // 排序问题，少于两个节点就直接返回
        if (!head || !head->next)
            return head;
        // dummy 用于两种情况：
        // 1. 既要删head，又要删非head时
        // 2. 有可能插在head时
        // 因此只是单一的删head就不用dummy了
        ListNode *pivot = head, *p = head->next, *tmp;
        pivot->next = NULL;
        ListNode *less = new ListNode(-1), *pl = less;
        ListNode *other = new ListNode(-1), *po = other;
        while (p) {
            // 先把要删的节点取下来
            // 再用取下来的节点去与pivot比较，选择要插入的位置
            tmp = p;
            p = p->next;
            tmp->next = NULL;
            if (tmp->val < pivot->val) {
                pl->next = tmp;
                pl = pl->next;
            } else {
                po->next = tmp;
                po = po->next;
            }
        }
        // 把两个排好序链表 与 pivot 串起来
        // 因为也是要插在头节点，所以也需要dummy
        ListNode *res = new ListNode(-1);
        p = res;
        p->next = sortList(less->next);
        while (p->next)
            p = p->next;
        p->next = pivot;
        p = p->next;
        p->next = sortList(other->next);
        head = res->next;
        delete less;
        delete other;
        delete res;
        return head;
    }
};