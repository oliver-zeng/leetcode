/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
    Node *pre = NULL, *head = NULL;
    void inorder(Node *root) {
        if (!root) return;
        inorder(root->left);
        // 中序遍历
        // 只要遍历到root时，root的左孩子 & root本身，就不再会被访问到了
        // 此时改变这些节点的指针，不会影响树上后面节点的遍历
        if (!pre) head = root;     // 先固定双链表的头结点
        else pre->right = root;    // root与pre的后继
        root->left = pre;          // root与pre的前驱
        pre = root;                // inorder结束时，pre就是双链表的尾结点
        inorder(root->right);
    }
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return NULL; // 一定记得对每一个容器参数做判空处理
        inorder(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
};