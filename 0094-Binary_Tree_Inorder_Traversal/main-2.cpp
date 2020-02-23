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
    // preOrder     遍历顺序是
    // inOrder      遍历顺序是左中右，所以压栈是按右中左
    // postOrder    遍历顺序是
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        vector<int> res;
        stack<pair<TreeNode*, bool>> s;
        s.push(make_pair(root, false));
        while (!s.empty()) {
            TreeNode *node = s.top().first;
            bool &visited = s.top().second;
            s.pop();
            if (visited)
                res.push_back(node->val);
            else {
                if (node->right) s.push(make_pair(node->right, false));
                s.push(make_pair(node, true));
                if (node->left) s.push(make_pair(node->left, false));
            }
        }
        return res;
    }
};