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
    void postorder(TreeNode *node) {
        if (!node)
            return;
        if (node->left) postorder(node->left);
        if (node->right) postorder(node->right);
        res.push_back(node->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return res;
    }
};