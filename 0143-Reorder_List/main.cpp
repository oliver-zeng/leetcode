/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // 链表问题一定要注意：
 // 不要在改变后的->next中去找变化后节点的所在位置，
 // 而是要在变化前提前找好，否则肯定会出错的
class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        bool even = true;
        ListNode *dummyHead = new ListNode(0), *p1 = dummyHead, *p2 = p1;
        dummyHead->next = head;
        // locate p1 at mid
        while (p2->next && p2->next->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        if (p2->next) {
            p1 = p1->next;
            p2 = p2->next;
            even = false;
        }
        // record (mid, tail]
        stack<ListNode*> st;
        p2 = p1->next;
        while (p2) {
            st.push(p2);
            p2 = p2->next;
        }
        // link
        ListNode *cur = head, *next, *tmp;
        while (!st.empty()) {
            next = cur->next;
            tmp = st.top();
            st.pop();
            cur->next = tmp;
            tmp->next = next;
            cur = next;
        }
        // even & odd
        if (even) {
            ListNode *tail = p1->next;
            tail->next = NULL;
        } else {
            tmp->next = p1;
            p1->next = NULL;
        }
    }
};
