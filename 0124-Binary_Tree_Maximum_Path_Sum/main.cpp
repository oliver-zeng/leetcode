// 用递归解决问题，需要做的最重要的事情，就是首先要定义好递归要解决的问题
// 对于一般问题，先要找出原问题与跟其相关的所有子问题间的关系，即递推关系式
// 而二叉树问题找子问题就相对简化了，因为这里的所有子问题，就是非常固定的左右两孩子
// 所以递推关系式要找的就是，当前节点与其左右两孩子间的关系
// 并且当前层的root就是下一层调用里root的父节点
// 而递归调用的返回值就是上一层左右孩子子问题的解
class Solution {

private:
    int res = INT_MIN;

public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }

private:
    // 用dfs遍历每一个点
    // 通过后序遍历得到左右子问题来计算以当前点为路径root的最大值
    int dfs(TreeNode* node){
         // 最大和肯定就要舍弃负值（max(0,x)）避免负优化
        int left = node->left ? dfs(node->left) : 0;
        int right = node->right ? dfs(node->right) : 0;

        res = max(res, node->val + max(0, left) + max(0, right));
        // dfs的返回的就是子问题的解，因为要以当前的root作为路径上的根
        // 所以dfs返回的是以root->child及root->child->left/right一边孩子组成的最大值
        return node->val + max(0, max(left, right));
    }
};