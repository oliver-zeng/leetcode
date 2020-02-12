class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* pre = dummyHead;
        ListNode* cur = head;
        ListNode* tmp;
        while(cur) {
            if (cur->val == val) {
                tmp = cur;
                pre->next = cur->next;
                cur = cur->next;
                delete tmp;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};
