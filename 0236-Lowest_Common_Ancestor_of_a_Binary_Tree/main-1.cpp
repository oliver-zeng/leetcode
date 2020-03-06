// 因为题目中规定 p & q 是不同的，且二者一定存在
// 所以不用考虑只有一个点的可能，一旦找到了一个，且其他孩子没有
// 那另一个就在找到的这一个的孩子里面
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (!root)
            return NULL;

        // 如果root就是答案
        if (root == p || root == q)
            return root;

        // 分别到左右子树中去找答案
        TreeNode* left =  lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // 两边各找到一个，root就是答案
        if (left && right)
            return root;

        // 一边一个都没有，另一边就肯定有两个，返回子问题答案
        if (left) return left;
        if (right) return right;

        // 两边一个都找不到，就返回NULL
        // 这是肯定可能的，因为在递归求解过程中，要查找的子树里就一个都没有
        return NULL;
    }
};