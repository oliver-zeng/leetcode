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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        if (root->val == p->val || root->val == q->val)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        // 两边都为空是可能的
        // 因为在递归过程中，查找的子树一个要找的节点都没有
        // 这时要返回NULL，此时不管另一边是否找到，直接返回另一边结果即可
        if (!left) return right;
        if (!right) return left;
        return root;
    }
};