#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createListNode(int arr[], int sz) {
    if (sz == 0)
        return NULL;
    ListNode* head = new ListNode(arr[0]);
    ListNode* cur = head;
    for (int i = 1; i < sz; i++) {
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    return head;
}

void printListNode(ListNode* head) {
    ListNode* p = head;
    while(p) {
        cout << p->val << " -> ";
        p = p->next;
    }
    cout << "null" << endl;
    return;
}

class Solution {
private:
    bool g_debug = false;
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // 建立哨兵节点，里面的value随意写一个，能调用构造就行
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;

        // 找到m-1与m节点
        ListNode* mPrev = dummyHead;
        ListNode* mNode;
        for (int i = 0; i < m - 1; i++, mPrev = mPrev->next);
        mNode = mPrev->next;
        if (g_debug)
            cout << "mPrev " << mPrev->val << " mNode " << mNode->val << endl;

        // 逆转从[m, n]的节点
        // 逆转完成，prev是节点n，cur是节点n+1
        int times = n - m + 1;
        ListNode* prev = mPrev;
        ListNode* cur = mNode;
        ListNode* next;
        while(times--) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        // mPrev -> [n, m] -> n + 1
        mPrev->next = prev;
        mNode->next = cur;

        // 释放哨兵节点
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};

int main() {
    int m = 2, n = 4;
    int arr[] = { 1,2,3,4,5 };
    //int m = 1, n = 1;
    //int arr[] = { 5 };
    ListNode* p = createListNode(arr, sizeof(arr)/sizeof(int));
    printListNode(p);
    Solution().reverseBetween(p, m, n);
    printListNode(p);

    return 0;
}
