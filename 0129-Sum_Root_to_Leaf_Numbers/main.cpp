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
    // number不是引用，每次都是传入的新值，所以不需要回退
    void dfs(TreeNode* root, int &sum, int number) {
        if (!root) return;
       	// 要先把值更新，后面存到sum，或者子树中都要使用这个新的值 
        number = number * 10 + root->val;
        if (!root->left && !root->right) {
            sum += number;
            return;
        }
        if (root->left)
        	dfs(root->left, sum, number);
        if (root->right)
        	dfs(root->right, sum, number);
    }
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0, number = 0;
        dfs(root, sum, number);
        return sum;
    }
};