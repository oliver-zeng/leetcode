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
private:
    vector<int> vec;
    void inOrder(TreeNode* root) {
        if (!root)
            return;

        if (root->left) inOrder(root->left);
        vec.push_back(root->val);
        if (root->right) inOrder(root->right);

        return;
    }
public:
    bool isValidBST(TreeNode* root) {
        inOrder(root);
        for (int i = 1; i < vec.size(); i++)
            if (vec[i] <= vec[i-1])
                return false;
        return true;
    }
};