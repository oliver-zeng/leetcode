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
    void deleteNode(ListNode* node) {
        // 这题的难点在于，根本没给head，只有node，拿不到node的前一个
        // 所以不是常规解：
        // 把node->next的val赋值给node，然后转变为删node->next
        ListNode *next = node->next->next;
        node->val = node->next->val;
        delete node->next;
        node->next = next;
        return;
    }
};
