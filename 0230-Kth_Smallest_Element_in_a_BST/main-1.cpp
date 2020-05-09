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
    int getSize(TreeNode* root) {
        if (!root)
            return 0;
        return getSize(root->left) + 1 + getSize(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root)
            throw invalid_argument("not found");

        int num = getSize(root->left);
        if (k == num + 1) {
            return root->val;
        } else if (k >= num + 1) {
            return kthSmallest(root->right, k - num - 1);
        } else { // k <= num + 1
            return kthSmallest(root->left, k);
        }
        
        throw invalid_argument("no way");
    }
};