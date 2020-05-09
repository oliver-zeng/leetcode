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
    int res = 0;
    void inorder(TreeNode* &node, int &k) {
        if (!node)
            return;
        inorder(node->left, k);
        k--;
        if (k == 0)
            res = node->val;
        inorder(node->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return res;
    }
};