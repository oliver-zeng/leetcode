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
    ListNode *dummyHead;
    int calcNum(int x, int &carry) {
        int num = x + carry;
        if (num >= 10) {
            num = num % 10;
            carry = 1;
        } else {
            carry = 0;
        }
        return num;
    }
    void createNode(int num) {
        ListNode *p = dummyHead->next;
        dummyHead->next = new ListNode(num);
        dummyHead->next->next = p;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        ListNode *p1 = l1, *p2 = l2;
        while (p1) {
            s1.push(p1->val);
            p1 = p1->next;
        }
        while (p2) {
            s2.push(p2->val);
            p2 = p2->next;
        }
        dummyHead = new ListNode(-1);
        int count = min(s1.size(), s2.size());
        int carry = 0;
        int num;
        while (count--) {
            num = calcNum(s1.top() + s2.top(), carry);
            createNode(num);
            s1.pop();
            s2.pop();
        }
        // 要注意到carry在短的链表没了的时候，carry也可以继续在长的上面算
        while(s1.size()) {
            num = calcNum(s1.top(), carry);
            createNode(num);
            s1.pop();
        }
        while(s2.size()) {
            num = calcNum(s2.top(), carry);
            createNode(num);
            s2.pop();
        }
        if (carry)
            createNode(carry);

        ListNode *p = dummyHead->next;
        delete dummyHead;
        return p;
    }
};
/*
        // 写的太累赘了，可以写成这样
        // carry 可以通过/10来得到，不需要判断是否>=10
        // 空栈也可以写在一个循环里，无非是加不上罢了
        while(!stack1.empty() || !stack2.empty() || carry){

            int x = 0;
            if(!stack1.empty()) x += stack1.top()->val, stack1.pop();
            if(!stack2.empty()) x += stack2.top()->val, stack2.pop();
            x += carry;

            stack.push(new ListNode(x % 10));
            carry = x / 10;
        }

        // 并且可以把整个栈都计算完，统一出栈
        // 就不需要考虑哪段多，拆成好几段来写了
        ListNode* ret = stack.top(), *cur = ret;
        stack.pop();
        while(!stack.empty())
            cur->next = stack.top(), cur = cur->next, stack.pop();

        // 而且因为栈里丢进去就是节点，而不是节点里的值
        // 这样把他们串起来就异常简单了，第一个就是头了，根本不需要dummyHead
        ListNode* ret = stack.top(), *cur = ret;
        stack.pop();
        while(!stack.empty())
            cur->next = stack.top(), cur = cur->next, stack.pop();
        return ret;

*/
