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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i])
                pq.push(make_pair(lists[i]->val, lists[i]));
        }
        ListNode *dummy = new ListNode(-1), *pre = dummy;
        while (!pq.empty()) {
            ListNode *tmp = pq.top().second;
            pq.pop();
            if (tmp->next)
                pq.push(make_pair(tmp->next->val, tmp->next));
            tmp->next = NULL;
            pre->next = tmp;
            pre = pre->next;
        }
        ListNode *res = dummy->next;
        delete dummy;
        return res;
    }
};