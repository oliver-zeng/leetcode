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
    bool hasCycle(ListNode *head) {
        // 赋初值前，先确保初值存在
        if (!head || !head->next) return false;
        ListNode *slow = head, *fast = head->next;
        while (slow != fast) {
            if (fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
            } else
                return false;
        }
        return true;
    }
};