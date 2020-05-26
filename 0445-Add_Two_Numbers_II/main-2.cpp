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
        ListNode *dummy = new ListNode(-1);
        int carry = 0;
        while (!st1.empty() || !st2.empty() || carry) {
            int num = carry;
            if (!st1.empty()) {
                num += st1.top();
                st1.pop();
            }
            if (!st2.empty()) {
                num += st2.top();
                st2.pop();
            }
            if (num >= 10) {
                num -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            // 因为是从高到低输出。所以每次新节点要插入头节点
            // 这里要用头插法，才能倒序输出栈中的结果
            ListNode *p = new ListNode(num);
            p->next = dummy->next;
            dummy->next = p;
        }
        ListNode *p = dummy->next;
        delete dummy;
        return p;
    }
};