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
    TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right) {
        // 当left == right创建一个节点
        if (left > right)
            return NULL;
        // 每次取[left, right]中间的点创建节点，这样左右最多就是差1的
        int mid = left + (right - left) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, left, mid - 1);
        root->right = sortedArrayToBST(nums, mid + 1, right);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // a height balanced BST => 最平衡的二叉树
        int sz = (int)nums.size();
        return sortedArrayToBST(nums, 0, sz - 1);
    }
};