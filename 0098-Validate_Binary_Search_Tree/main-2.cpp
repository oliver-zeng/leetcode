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
    bool isValidBST(TreeNode* root, int floor, int ceil, bool fg, bool cg) {
        if (!root)
            return true;

        if((fg && root->val <= floor) || (cg && root->val >= ceil))
            return false;

        // 要左右两边都遍历完才能返回，所以只遍历完一边的结果还不能返回
        // 直到两边都遍历完，都为true，结果才为true
        // 还是 floor 或 ceil 的就延续参数中传进来的 flag
        return isValidBST(root->left, floor, root->val, fg, true) && isValidBST(root->right, root->val, ceil, true, cg);
    }

public:
    bool isValidBST(TreeNode* root) {
        // 这里对第一个节点root提供的上下边界，只是一个虚假值
        // 为了避免root真的是这个虚假值，还需要为每一个虚假值设立 flag
        // 只有 flag 为 true 的值，才能作为上下界标准，用于实际判断
        return isValidBST(root, INT_MIN, INT_MAX, false, false);
    }
};