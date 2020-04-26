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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next)
            return NULL;
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            // 先移动
            slow = slow->next;
            fast = fast->next->next;
            // 后判断
            // 从而完美避开从同一个点开始的追击问题
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        // 无环
        return NULL;
    }
};