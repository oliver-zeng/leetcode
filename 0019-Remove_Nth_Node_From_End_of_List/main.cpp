#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createListNode(int arr[], int sz) {
    if (sz == 0)
        return NULL;
    ListNode *head = new ListNode(arr[0]), *p = head;
    for (int i = 1; i < sz; i++) {
        p->next = new ListNode(arr[i]);
        p = p->next;
    }
    return head;
}

void printListNode(ListNode *head) {
    ListNode *p = head;
    while(p) {
        cout << p->val << " -> ";
        p = p->next;
    }
    cout << " null" << endl;
}

class Solution {
private:
    bool g_debug = false;
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode *pre = dummyHead, *nth = pre, *next;
        // nth从pre往后数n个，这样pre->next距离nth就是n个
        for (int i = 0; i < n; i++)
            nth = nth->next;
        // 再保持pre与nth的距离同时移动
        // 当nth移动到最后一个节点时，pre->next就是要删的节点
        while (nth->next) {
            pre = pre->next;
            nth = nth->next;
        }
        if (g_debug)
            cout << "pre " << pre->val << " nth " << nth->val << endl;
        ListNode *res;
        // 数组看index是否越界，链表看指针是否为NULL
        // 这里的pre->next->next是不一定有的
        // 所以必须要对pre->next为空做特殊处理
        if (!pre->next)
            next = NULL;
        else
            next = pre->next->next;
        delete pre->next;
        pre->next = next;
        res = dummyHead->next;
        delete dummyHead;
        return res;
    }
};

int main() {
    //int arr[] = { 1,2,3,4,5 };
    //int k = 2;
    int arr[] = {1};
    int k = 1;
    ListNode *p = createListNode(arr, sizeof(arr)/sizeof(int));
    printListNode(p);
    p = Solution().removeNthFromEnd(p, k);
    printListNode(p);

    return 0;
}
