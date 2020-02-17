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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 && l2){}
        ListNode* result;
        ListNode* tail;
        ListNode* elm;
        bool carry = false;
        bool first = true;
        unsigned int sum;
        while (l1 && l2){
            
        	sum = l1->val + l2->val;
        	if (first) {
            	if (sum >= 10) carry = true; // must >=
            	elm = new ListNode(sum % 10);
                result = elm;
                first = false;
        	} else {
            	if (carry) sum += 1;
            	elm = new ListNode(sum % 10); // must new
            	if (sum >= 10) carry = true;
            	else carry = false;
            
            	tail = result; // list need aadd a tail for easy push_back 
            	while(tail->next)
                	tail = tail->next;
            	tail->next = elm;
        	}
        	l1 = l1->next;
            l2 = l2->next;
        }
        
        while (l1) {
            sum = carry ? l1->val + 1 : l1->val;
            carry = sum >= 10 ? true : false;
            elm = new ListNode(sum%10);
            
            tail = result;
            while(tail->next)
                tail = tail->next;
            tail->next = elm;
            
            l1 = l1->next;
        }
        
        while (l2) {
            sum = carry ? l2->val + 1 : l2->val;
            carry = sum >= 10 ? true : false;
            elm = new ListNode(sum%10);
            
            tail = result;
            while(tail->next)
                tail = tail->next;
            tail->next = elm;
            
            l2 = l2->next;
        }
        
        if (carry) {
            elm = new ListNode(1);
            
            tail = result;
            while(tail->next)
                tail = tail->next;
            tail->next = elm;
        }
        
        return result;
    }
};
