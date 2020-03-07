class Solution {
public:
    // 通过dfs可以直接找到子节点与父节点
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        // 如果key大于root->val，递归到右子树删除
        if (root->val < key)
            root->right = deleteNode(root->right, key);
        // 如果key小于root->val，递归到左子树删除
        else if (key < root->val)
            root->left = deleteNode(root->left, key);
        else { // 找到了root->val等于key的root
            if (root->left) { // 如果左孩子存在，用前驱替代，改为删前驱
                TreeNode *tmp = root->left;
                while (tmp->right)
                    tmp = tmp->right;
                root->val = tmp->val;
                root->left = deleteNode(root->left, root->val);
            } else if (root->right) { // 如果右孩子存在，用后继替代，改为删后继
                TreeNode *tmp = root->right;
                while (tmp->left)
                    tmp = tmp->left;
                root->val = tmp->val;
                root->right = deleteNode(root->right, root->val);
            } else { // 左右孩子都没有的叶子，直接删掉，父节点孩子设为NULL
                delete root;
                root = NULL;
            }
        }

        // 传递给父节点的孩子
        // 只有在真的删除后，才会变为NULL
        // 替换的话，父节点与子节点关系不变
        return root;
    }
};