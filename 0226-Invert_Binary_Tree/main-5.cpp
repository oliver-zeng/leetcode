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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            // 把左右对调后，右边就是左子树，左边就是右子树
            // 所以要先push右边，再push左边，才是对调后的正确遍历顺序
            if (node->right) st.push(node->right); // 一定注意push进去的是非空节点
            if (node->left) st.push(node->left);
            swap(node->left, node->right);
        }
        return root;
    }
};