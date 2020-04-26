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
        unordered_set<ListNode*> st;
        while (head) {
            if (st.count(head))
                return head;
            st.insert(head);
            head = head->next;
        }
        // 无环
        return NULL;
    }
};