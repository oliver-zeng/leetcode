/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 1.先要找到准备指针域要发生变化节点的前一个
//   这里是dummyHead，待遍历完dummyHead->next将会指向链表的最后一个节点
//   这题的第一个元素是会指向null的，从第二个元素开始才是正常指向前一个元素
//   所以直接将dummyHead的位置改为null即可，这样变化位置从第一个cur = dummyHead->next开始
// 2.定位要用到的辅助位置
//   需要知道cur->next指向的pre，以及改变cur->next前要先记录的next
// 3.其次要判断要改变的节点位置上是否真的存在元素，看是否可以发生变化
// 4.指针域改变完后，将改变位置指针与辅助指针移动到下一个
//   这里通过提前记录在未改变前指针域前的位置，直接跳到下一个
//   千万不要在指针改变后，通过改变后的->next移动过去，这样很容易出错
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* after;
        // 1.要改变的是cur，结束条件为判断要改变的是否存在
        while (cur) {
            // 2. 辅助为after与pre
            after = cur->next;
            // 3. 改变cur的指针域
            cur->next = prev;
            // 4. 跳到下一个cur的位置
            prev = cur;
            cur = after;
        }
        return prev;
    }
};
