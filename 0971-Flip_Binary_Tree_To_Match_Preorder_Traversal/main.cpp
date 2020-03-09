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
int index = -1;
vector<int> flip;
bool preorder(TreeNode *root, vector<int>& voyage) {
    if (!root)
        return true;;
    index++;
    if (voyage[index] != root->val)
        return false;
    // 先序遍历，下一个出来的一定是左孩子，左孩子不等就swap
    if (root->left && voyage[index + 1] != root->left->val) {
        swap(root->left, root->right);
        flip.push_back(root->val);
    }
    // 如果左孩子为空且不等，同root->val不等一样，是无法通过swap修正的
    if (preorder(root->left, voyage) &&
        preorder(root->right, voyage))
        return true;
    
    return false;
}
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        if (preorder(root, voyage))
            return flip;
        else
            return {-1};
    }
};