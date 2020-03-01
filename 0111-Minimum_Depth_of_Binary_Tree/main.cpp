/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 递推式法解
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        int res = INT_MAX;
        if (root->left) res = min(res, 1 + minDepth(root->left));
        if (root->right) res = min(res, 1 + minDepth(root->right));
        if (res != INT_MAX)
            return res;
        else
            return 1;
    }
};