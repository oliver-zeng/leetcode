/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 对于有的节点变化，有的不变化的问题
// 不要在变化后，通过移动指针，从不变化的过渡到下一个变化，这样非常容易出错
// 因为指针在经过变化后，位置都变了，在从变化的位置，移动就很容易出错
// 聪明地规避掉的方法是，只用指针处理变化的部分，然后直接跳到下一个要变化的位置，
// 而不是变化前指针经过变化后，再移动到下一个要变化的位置去
// 当然，每次跳到正确的位置，都要先判断位置后续节点是否足够，可以进行变化
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;

        // 先用一个定位指针找到要做变化的位置
        // 找到后判断是否能做变化
        ListNode *cur = dummyHead;
        while(cur->next && cur->next->next) {
            // 若能在做具体变化时，先根据定位指针申请其他辅助指针
            // （避免出现x->next->next这样极易出错）
            ListNode *node1 = cur->next;
            ListNode *node2 = cur->next->next;
            ListNode *next = node2->next;
            // 最后在做变化，改变各节点的指针域（为->next赋值）
            cur->next = node2;
            node2->next = node1;
            node1->next = next;
            // 最后再将定位指针，指向下一个要做变化的位置（注意不是靠next移动过去）
            cur = node1;
        }
        cur = dummyHead->next;
        delete dummyHead;
        return cur;
    }
};
