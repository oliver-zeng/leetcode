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
    unordered_map<void*, int> memo;
    int calcRob(TreeNode* root) {
        if (root == NULL) return 0;
        if (memo.count(root)) return memo[root];
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        int with_root = (l == NULL ? 0 : calcRob(l->left)+calcRob(l->right))+(r == NULL ? 0 : calcRob(r->right)+calcRob(r->left)) + root->val;
        int no_root = calcRob(l)+calcRob(r);
        return memo[root] = max(with_root, no_root);
    }
public:
    int rob(TreeNode* root) {
        return calcRob(root);
    }
};
