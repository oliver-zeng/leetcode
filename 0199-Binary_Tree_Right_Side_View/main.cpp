/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 深度优先，顺着一条链能走下来
// 广度优先，不是按照一条链走下来的
// 层序遍历在每层只能，都是从左向右数，或都从右向左
// 如果要个别调整，需要遍历完再操作，否则会拧麻花
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
        queue<pair<int, TreeNode*>> q;
        q.push(make_pair(0, root));
        // 答案无法根据沿着 left & right 一条链走下来
        // 只能用层序遍历得到答案
        //     1
        //    / \
        //   2   3
        //  /
        // 4
        while (!q.empty()) {
            int level = q.front().first;
            TreeNode *node = q.front().second;
            q.pop();
            if (level == res.size())
                res.push_back(node->val);
            if (node->right) q.push(make_pair(level+1, node->right));
            if (node->left) q.push(make_pair(level+1, node->left));
        }

        return res;
    }
};
