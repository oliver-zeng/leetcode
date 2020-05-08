/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 判断bst，不能只看left < mid < right
// 因为要确保子树上所有节点都在(floor, ceil)之间
//   2
//  / \
// 1   3
//  \
//   3 <- wrong
class Solution {
    bool inorder(TreeNode* root, long long floor, long long ceil) {
        if (!root)
            return true;
        cout << "floor " << floor << " ceil " << ceil << endl;
        // !(!A || !B) <=> A && B
        if (!(root->val < ceil) || !(root->val > floor))
            return false;
        return inorder(root->left, floor, root->val) && inorder(root->right, root->val, ceil);
    }
public:
    bool isValidBST(TreeNode* root) {
        // val值是int类型，所以用long long可以实现真正意义上的正负无穷
        //return inorder(root, INT_MIN, INT_MAX);
        return inorder(root, LONG_MIN, LONG_MAX);
    }
};