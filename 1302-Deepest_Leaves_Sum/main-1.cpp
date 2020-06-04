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
    void dfs(TreeNode* root, int depth, int &res, int &max_depth) {
        if (!root) return;
        // 在dfs中不断更新最深层信息的思路
        if (depth > max_depth) { // 若找到更深层，res重新赋值更深层第一个数
            max_depth = depth;
            res = root->val;
        } else if (depth == max_depth) { // res不断累积当前最深层节点的和
            res += root->val;
        }
		if(root->left) dfs(root->left, depth+1, res, max_depth);
        if(root->right) dfs(root->right, depth+1, res, max_depth);
        return;
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        if (!root) return 0;
        int res = 0, max_depth = 0;
		dfs(root, 1, res, max_depth);
        return res;
    }
};