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
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        // 设立虚拟值的情况，一定要考虑到没有更新过的虚拟值是不能使用的
        // 要通过flag标记出来，对还是虚拟值的case做特殊处理
        int res = INT_MAX;
        bool flag = false;
        // 只去考虑有孩子的方向，避免只有一个孩子的节点带入错误的最小高度
        if (root->left) {
            res = min(res, 1 + minDepth(root->left));
            flag = true;
        }
        if (root->right) {
            res = min(res, 1 + minDepth(root->right));
            flag = true;
        }
        if (flag)
            return res;
        else // 前面两次递归都没有走进的情况，是左右孩子都为空的叶子，高度为1
            return 1;
    }
};