#include <iostream>
#include <vector>

using namespace std;

/// Linear Scan and Recursive Reverse
/// Time Complexity: O(n)
/// Space Complexity: O(k)

/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    bool g_debug = false;
    // reverse [rtail, rhead]
    void reverse(ListNode *rtail, ListNode *rhead) {
        ListNode *pre = NULL, *cur = rtail, *next;
        while (pre != rhead) {
            if (g_debug)
                cout << "[reverse] " << cur->val << endl;
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        // 等找到第k个逆转的位置就晚了，没法逆置了
        // 但边逆转边走，可能发现不到k，不该逆转，还要再次逆回来
        // 两次逆转加大出错难度，肯定不选
        // 所以逆转前，先看有没有k个，够再逆转，否则直接返回
        // locate:
        // dummy -> 1 -> .. -> k
        //  pre   rtail      rhead  next
        ListNode *pre = dummyHead, *rtail = pre->next, *rhead, *next;
        while (pre) {
            rhead = pre;
            int i = 0;
            // 这里的错因在于：
            // rhead不是位于第一个计数节点，而是在第一个的前一个
            // 所以第一个总是存在的，会多算一个
            //for (; i < k && rhead; i++)
            for (; i < k && rhead->next; i++)
                rhead = rhead->next;
            if (g_debug)
                cout << "i " << i << endl;
            if (i != k)
                break;
            next = rhead->next;
            if (g_debug)
                cout << "pre " << pre->val << " rtail " << rtail->val << " rhead " << rhead->val << " next " << next->val << endl;
            // 每个操作要用不同的指针，千万不要复用
            // 两套操作一个位置错了，后面很难查出来
            // 第一个操作是拼接，那逆置的操作就单放在reverse函数里
            // 只改变指针域的话，定位指针所指向的节点都不会变化
            // 在reverse完，可用reverse前定位的指针进行拼接
            reverse(rtail, rhead);
            pre->next = rhead;
            rtail->next = next;
            pre = rtail;
            rtail = next;
            if (g_debug)
                cout << "done" << endl;
        }

        pre = dummyHead->next;
        delete dummyHead;
        return pre;
    }
};

/// LinkedList 测试辅助函数

// 根据n个元素的数组arr创建一个链表, 并返回链表的头
ListNode* createLinkedList(const vector<int>& arr){

    if(arr.size() == 0)
        return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* curNode = head;
    for(int i = 1 ; i < arr.size() ; i ++){
        curNode->next = new ListNode(arr[i]);
        curNode = curNode->next;
    }

    return head;
}

// 打印以head为头结点的链表信息内容
void printLinkedList(ListNode* head){

    ListNode* curNode = head;
    while(curNode != NULL){
        cout << curNode->val << " -> ";
        curNode = curNode->next;
    }

    cout << "NULL" << endl;

    return;
}

// 释放以head为头结点的链表空间
// use after free
void deleteLinkedList(ListNode* head){

    ListNode* curNode = head;
    while(curNode != NULL){
        ListNode* delNode = curNode;
        curNode = curNode->next;
        delete delNode;
    }

    return;
}


int main() {

    vector<int> arr1 = {1, 2, 3, 4, 5};
    ListNode* res1 = Solution().reverseKGroup(createLinkedList(arr1), 2);
    // 3 2 1
    printLinkedList(res1);
    deleteLinkedList(res1);

    return 0;
}
