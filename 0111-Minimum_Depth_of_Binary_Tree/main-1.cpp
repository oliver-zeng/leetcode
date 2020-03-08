/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 这题跟树高最大的问题（LeetCode 104）不同之处在于
// 树高最大的肯定是一条由 root 到 leaf 的路径
// 但树高为0的点是只有一个孩子节点，并不是一条到leaf路径，不能考虑进去
// 所以对每个节点的处理，要按有几个孩子分类讨论
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        // 叶子自身高度为1 => 可以融到 numLeft + numRight + 1 里
        // 但把可以提前结束的递归结束条件，挪到后面去会有超时风险
        if (!root->left && !root->right)
            return 1;
        // 分别求左右子树最小高度
        int numLeft = minDepth(root->left);
        int numRight = minDepth(root->right);
        // 在一开始已经对叶子进行过判断了
        // 这里若有一边为空树高就为0，就去找另一边的树高
        if (!root->left || !root->right)
            return numLeft + numRight + 1;
        // 最后一种情况就是，两边都不为空，找最小的那边
        return min(numLeft, numRight) + 1;
    }
};