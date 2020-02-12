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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;

        ListNode *odd = new ListNode(-1);
        ListNode *pOdd = odd;
        ListNode *even = new ListNode(-1);
        ListNode *pEven = even;

        ListNode* p = dummyHead->next;
        int count = 1;
        while(p) {
            if (count % 2) {
                pOdd->next = p;
                p = p->next;
                pOdd = pOdd->next;
                pOdd->next = NULL;
            } else {
                pEven->next = p;
                p = p->next;
                pEven = pEven->next;
                pEven->next = NULL;
            }
            count++;
        }

        pOdd->next = even->next;
        head = odd->next;
        delete odd;
        delete even;
        return head;
    }
};
