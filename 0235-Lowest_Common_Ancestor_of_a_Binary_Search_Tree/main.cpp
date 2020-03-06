class Solution {

private:
    TreeNode* ret = 0;

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return NULL;

        // 通过val值，可以直接知道 p & q 是在 left 还是 right
        if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p , q);
        
        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p , q);
        // p q 不全在一边，则root就是LCA
        return root;
    }
};