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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root)
        	return false;
        if (root->left || root->right) { // 不是叶子，以sum - val的值在子树中判断
            // 因为有负数-2 + -3 = -5
            // 所以没法通过非叶子节点都值来提前结束
            // 因此不做判断，直接在叶子判断即可
            //if (root->val >= sum)
            //	return false;
            return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
        } else { // 是叶子，判断sum
            if (root->val == sum)
            	return true;
            return false;
        }
    }
};