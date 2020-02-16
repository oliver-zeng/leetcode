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
    ListNode* popList(ListNode* &list) {
        ListNode *tmp = list;
        list = list->next;
        return tmp;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // greater是可以比较pair<key, val>的，会比较key的大小
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // 先每个装一个
        int sz = lists.size();
        ListNode *tmp;
        for (int i = 0; i < sz; i++) {
            if (lists[i]) {
                tmp = popList(lists[i]);
                pq.push(make_pair(tmp->val, i));
                delete tmp;
            }
        }
        // 将找到最值的再补上一个，插入链表即可
        ListNode *dummyHead = new ListNode(-1);
        ListNode *cur = dummyHead;
        while (!pq.empty()) {
            cur->next = new ListNode(pq.top().first);
            cur = cur->next;
            if (lists[pq.top().second]) {
                tmp = popList(lists[pq.top().second]);
                pq.push(make_pair(tmp->val, pq.top().second));
                delete tmp;
            }
            pq.pop();
        }
        tmp = dummyHead->next;
        delete dummyHead;
        return tmp;
    }
};
