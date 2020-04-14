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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 对于逆序处理应该首先想到栈
        stack<int> st1;
        stack<int> st2;
        while (l1) {
            st1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            st2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        ListNode *dummy = new ListNode(-1);
        ListNode *p = dummy;
        while (!st1.empty() || !st2.empty() || carry) {
            int num1 = st1.empty() ? 0 : st1.top();
            int num2 = st2.empty() ? 0 : st2.top();
            if (!st1.empty())
                st1.pop();
            if (!st2.empty())
                st2.pop();
            int sum = num1 + num2 + carry;
            if (sum >= 10) {
                carry = 1;
                sum -= 10;
            } else
                carry = 0;
            // 因为是从高到低输出。所以每次新节点要插入头节点
            p = new ListNode(sum);
            p->next = dummy->next;
            dummy->next = p;
        }
        p = dummy->next;
        delete dummy;
        return p;
    }
};