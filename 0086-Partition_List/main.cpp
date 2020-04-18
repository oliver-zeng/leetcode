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
    ListNode* partition(ListNode* head, int x) {
        // 因为less & other有可能插到表头，所以需要dummy
        // 遍历head，不涉及表头的插入&删除，则不需要dummy
        ListNode *less = new ListNode(-1), *pl = less;
        ListNode *other = new ListNode(-1), *po = other;
        ListNode *p = head;
        while (p) {
            if (p->val < x) {
                // 这里必须是马上接 p = p->next
                // 否则 pl->next = NULL 会令 p->next 变为0
                // 还是老思路，先取再插，才不会错
                // 取必须严格2步：先把要取的节点存到临时指针，再连接取后的链表
                // 插也要严格2步：后面没有了也必须要加NULL，这样才能从取出的链中真正断链
                // 这里特殊在 pl 已在链尾，不会丢后面的链，所以可以提前赋值，从而节省了一个存放取下来节点的tmp
                pl->next = p;
                p = p->next;
                pl = pl->next;
                pl->next = NULL;
            } else {
                po->next = p;
                p = p->next;
                po = po->next;
                po->next = NULL;
            }
        }   
        pl->next = other->next;
        head = less->next;
        delete less;
        delete other;
        return head;
    }
};