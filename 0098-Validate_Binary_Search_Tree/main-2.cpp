/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    // 中序遍历，与前一个输出的node->val进行比较
    bool inorder(TreeNode* node, long long &pre) {
        if (!node)
            return true;
        if(!inorder(node->left, pre))
            return false;
        // 隐式转换，会转换成空间最大的进行比较
        // 空间相同时，会转换成无符号的进行比较
        // 所以int sz = vec.size()，if (sz > -1)会出错
        if (pre >= node->val)
            return false;
        pre = node->val;
        return inorder(node->right, pre);
    }
public:
    bool isValidBST(TreeNode* root) {
        long long pre = LONG_MIN;
        return inorder(root, pre);
    }
};