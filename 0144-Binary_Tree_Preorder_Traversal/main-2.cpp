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
    // 树的深度遍历，天然就是递归遍历
    // 而递归的本质，实际就是栈操作
    // 所以能用递归解的，必然也可以通过栈来实现
    // 前中后就是栈出栈时的处理顺序
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        if (root) s.push(root);
        while (!s.empty()) {
            TreeNode *node = s.top();
            s.pop();
            res.push_back(node->val);
            // 这里是跟递归版实现，相反的地方
            // 通过用栈本质上实现的是延时输出，left会早于right被处理
            // 所以在栈中是先放入right，后放left
            if (node->right) s.push(node->right);
            if (node->left) s.push(node->left);
        }

        return res;
    }
};
