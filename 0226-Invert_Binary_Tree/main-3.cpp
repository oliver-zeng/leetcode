// BFS 广度优先（Breadth-First-Search）
// left先进队，就是从左到右的层序遍历；right先进，就是从右到左
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        queue<TreeNode*> qe;
        qe.push(root);
        while (!qe.empty()) {
            TreeNode *node = qe.front();
            qe.pop();
            swap(node->left, node->right);
            // 此题交换左右子树的操作，可以在左右孩子进队前或进队后，但就不能是中间
            // 中间就相当于是，先左子树交换完成，把左右孩子对调，再处理对调后的右子树
            // 相当于又继续处理了一遍之前交换过了的左子树，真正的右子树没动
            if (node->left) qe.push(node->left);
            if (node->right) qe.push(node->right);
        }
        return root;
    }
};