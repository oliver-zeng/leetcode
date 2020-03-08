class Solution {

public:
    int pathSum(TreeNode* root, int sum) {

        if (root == NULL)
            return 0;
        // 树的问题，可以通过递归调用左右子树，用dfs地遍历每个节点
        // 然后每次只要处理当前的root节点即可
        return findPath(root, sum)
                + pathSum(root->left , sum)
                + pathSum(root->right , sum);
    }

private:
    int findPath(TreeNode* node, int num){

        if(node == NULL)
            return 0;
        // 递归问题的累积解，可以直接定义在递归内部
        // 最后返回的是最外层的累积解
        // 所以递归地用左右子树去更新向外层输出的累积解即可
        int res = 0;
        if(node->val == num)
            res += 1;
            // 数字有正有负，所以就算已经找到了一个解，也不能够返回
            // 因为后面可能还会有别的解，因此还要继续dfs
            //return;

        res += findPath(node->left , num - node->val);
        res += findPath(node->right , num - node->val);

        return res;
    }
};