// preorder：
// 先交换左右子树，再对左右子树逆置
// postorder：
// 跟先对左右孩子逆置完，最后交换左右子树都可以
// inorder：
// 不行，相当于换完左子树后，交换了左右孩子
// 最后逆置新的右孩子，相当于又把左子树换了一遍
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};