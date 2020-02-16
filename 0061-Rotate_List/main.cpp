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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return NULL;
        // 先统计一次链表长度，排除无用循环，否则会超时
        ListNode *p = head;
        int sz = 1;
        // 链表统计个数，必须以next作为判断条件
        // 否则结束循环时p会指在NULL，相当于是从第一个数到NULL会多一个
        while (p->next) {
            sz++;
            p = p->next;
        }
        k = k % sz;
        if (g_debug)
            cout << "k " << k << " sz " << sz << endl;
        // 正式开始rotate
        ListNode *dummyHead = new ListNode(0), *pre = dummyHead, *cur = head, *first;
        dummyHead->next = head;
        while (k--) {
            // 1. 定位改变指针域节点位置 & 判断是否存在
            while (cur && cur->next) {
                pre = pre->next;
                cur = cur->next;
            }
            // 2. 若存在，变更指针域
            pre->next = NULL;
            first = dummyHead->next;
            cur->next = first;
            dummyHead->next = cur;
            // 3. 重新找到下一次的位置
            pre = dummyHead;
            cur = dummyHead->next;
        }
        first = dummyHead->next;
        delete dummyHead;
        return first;
    }
};
