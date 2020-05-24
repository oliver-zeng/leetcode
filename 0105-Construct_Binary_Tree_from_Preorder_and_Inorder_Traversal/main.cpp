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
    TreeNode* dfs(vector<int> &preorder, vector<int> &inorder, unordered_map<int, int>  &dict, 			int pre_left, int pre_right, int in_left, int in_right) {
        if (pre_left > pre_right || in_left > in_right)
        	return NULL;
        // preorder: [根节点, [左子树的前序遍历结果], [右子树的前序遍历结果]]
		int root_val = preorder[pre_left];
        // inorder:  [[左子树的中序遍历结果], 根节点, [右子树的中序遍历结果]]
        int in_root = dict[preorder[pre_left]];
        int left_childs = in_root - in_left; // [in_left, in_root)
        TreeNode* root = new TreeNode(root_val);
        root->left = dfs(preorder, inorder, dict, pre_left+1, pre_left+left_childs, in_left, in_root-1);
        root->right = dfs(preorder, inorder, dict, pre_left+left_childs+1, pre_right, in_root+1, in_right);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 可通过节点值找到中序遍历索引
		unordered_map<int, int> dict;
        for (int i = 0; i < inorder.size(); i++)
        	dict[inorder[i]] = i;
		return dfs(preorder, inorder, dict, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};