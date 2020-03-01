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
    int res = 0;
    void dfs (TreeNode *node, int level) {
        if (node) {
            res = max(res, level + 1);
            dfs (node->left, level + 1);
            dfs (node->right, level + 1);
        }
    }
public:
    int maxDepth(TreeNode* root) {
        dfs (root, 0);
        return res;
    }
};