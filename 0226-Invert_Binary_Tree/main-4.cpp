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
    TreeNode* mirrorTree(TreeNode* root) {
        if (!root)
            return NULL;

        #ifdef WRONG
        // 翻转前要把正确的存起来，否则会丢失
        root->left = mirrorTree(root->right);
        root->right = mirrorTree(root->left);
        #else
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = mirrorTree(right);
        root->right = mirrorTree(left);
        #endif

        return root;
    }
};