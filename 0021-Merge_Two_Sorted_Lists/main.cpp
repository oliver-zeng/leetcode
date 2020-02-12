class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // dummy的标准写法，只要能调用构造就行，参数无所谓
        // 有head就是dummyHead->next=head; cur = head;
        // 没有head就是cur = dummyHead; 后面再看情况添加
        ListNode* dummyHead = new ListNode(-1);
        ListNode* cur = dummyHead;
        while (l1 && l2) {
            if(l1->val <= l2->val) {
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            }
        }

        cur->next = l1 ? l1 : l2;
        // 最后的返回值是dummyHead->next
        // 返回前把dummyHead删除掉
        cur = dummyHead->next;
        delete dummyHead;
        return cur;
    }
};
