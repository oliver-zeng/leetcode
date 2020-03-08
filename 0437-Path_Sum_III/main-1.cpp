class Solution {
private:
    int res = 0;
    void getPath(TreeNode* root, int sum) {
        if (!root)
            return;
        if (root->val == sum) {
            res++;
            // 数字有正有负，所以就算已经找到了一个解，也不能够返回
            // 因为后面可能还会有别的解，因此还要继续dfs
            //return;
        }
        getPath(root->left, sum - root->val);
        getPath(root->right, sum - root->val);
        return;
    }
    void dfs(TreeNode* root, int sum) {
        if (!root)
            return;
        getPath(root, sum);
        dfs(root->left, sum);
        dfs(root->right, sum);
        return;
    }
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root)
            return 0;
        dfs(root, sum);
        return res;
    }
};