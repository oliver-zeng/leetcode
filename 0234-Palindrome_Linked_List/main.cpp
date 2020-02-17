/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    bool g_debug = false;
public:
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;

        ListNode *p1 = dummyHead, *p2 = p1;
        while (p2->next && p2->next->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        if (p2->next)
            p1 = p1->next;
        ListNode *p = p1->next;
        if (g_debug)
            cout << "p1 " << p1->val << "p1 next " << p->val << endl;
        stack<int> pq;
        while (p) {
            if (g_debug)
                cout << "[push] " << p->val << endl;
            pq.push(p->val);
            p = p->next;
        }
        p = dummyHead->next;
        while (!pq.empty()) {
            if (g_debug)
                cout << "top " << pq.top() << " p " << p->val << endl;
            if (pq.top() != p->val)
                return false;
            p = p->next;
            pq.pop();
        }
        return true;
    }
};
