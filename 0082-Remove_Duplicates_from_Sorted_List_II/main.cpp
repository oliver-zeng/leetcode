/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 这题要做的是出现下面情况时，把pre与here接上
// [1, 2, (2, 2, 2,) 3, ..]
// pre cur         here
// 所以要检测的重点是，到底有没有小括号里复数个跟cur->val一样的值
// 从p = cur开始遍历，直至出现p->val不等于cur->val的点，看经历的节点数是否超过1个
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode *pre = dummyHead, *cur = head;
        ListNode *p = cur;
        while (cur) {
            int num = 0;
            while (p && p->val == cur->val) {
                num++;
                p = p->next;
            }
            if (num > 1) {
                pre->next = p;
                cur = p;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        return dummyHead->next;
    }
};
