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
    void dfs(TreeNode* root, int sum, vector<vector<int>> &res, vector<int> &tmp) {
        if (!root) return;
        if (!root->left && !root->right) {
            if (sum == root->val) {
                // dfs调用完会把tmp值退回去
                // res用完，也需要回退tmp
                tmp.push_back(root->val);
                res.push_back(tmp);
                tmp.pop_back();
            }
            return;
        }
        if (root->left) {
            tmp.push_back(root->val);
			dfs(root->left, sum - root->val, res, tmp);
            tmp.pop_back();
        }
        if (root->right) {
            tmp.push_back(root->val);
            dfs(root->right, sum - root->val, res, tmp);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(root, sum, res, tmp);
        return res;
    }
};