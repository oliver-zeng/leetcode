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
    TreeNode* res = NULL;
    bool dfs (TreeNode* root, TreeNode* p, TreeNode* q) {

        if (!root) return false;

        bool mid = false;
        if (root == p || root == q)
            mid = true;
        bool left = dfs(root->left, p, q);
        bool right = dfs(root->right, p, q);
        // bool加法用法
        // 三个bool相加 >= 2，表示三个条件有两个满足
        // 左中右里面能找到两个点，那中间的点就是LCA
        if (left + mid + right >= 2)
            res = root;

        return (left + mid + right > 0);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs (root, p, q);
        return res;
    }
};