/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 对于链表问题，要使节点不动，也就是节点都存储地址不变
// 只通过改变的是节点都指针域来实现
// 否则存储位置都变了，那就没必要使用链表了
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* after;
        while (cur) {
            // 2. 记录要改变当前指针cur，原本的值，指针后面内容不能丢
            after = cur->next;
            // 3. 为当前指针cur赋值
            cur->next = prev;
            // 1. 当前指针cur要赋的值，要提前算出
            prev = cur;
            cur = after;
        }
        return prev;
    }
};
