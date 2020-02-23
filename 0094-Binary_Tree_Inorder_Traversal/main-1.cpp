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
private:
    vector<int> res;
    // preOrder inOrder postOrder
    void inorder(TreeNode *node) {
        if (node) {
            if (node->left) inorder(node->left);
            res.push_back(node->val);
            if (node->right) inorder(node->right);
        }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return res;
    }
};
