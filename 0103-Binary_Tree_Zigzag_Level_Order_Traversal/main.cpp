/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 层序遍历在每层只能都是从左向右数，或都从右向左
// 如果要个别调整，需要遍历完再操作，否则会拧麻花
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        queue<pair<int, TreeNode*>> q;
        // 这里root level要从0开始
        // 因为level会作为返回值vector的index使用
        // 空出一个0从1开始，跟预期输出就不同了
        q.push(make_pair(0, root));

        // 层序遍历，必须统一左孩子后右孩子的顺序放进去
        // 如果偶数反过来按先右孩子再左孩子，那下一层的3永远也到不了4前面了
        // 所以先都放进去vector，之后再对需要逆转的部分操作
        //     0
        //    / \
        //   1   2
        //  /     \
        // 3       4
        while (!q.empty()) {
            int level = q.front().first;
            TreeNode *node = q.front().second;
            q.pop();
            if (level == res.size())
                res.push_back(vector<int>());
            res[level].push_back(node->val);
            if (node->left) q.push(make_pair(level+1, node->left));
            if (node->right) q.push(make_pair(level+1, node->right));
        }

        // std::reverse
        // vector也有iter，stack & queue ？
        // for (int i=1; i<10; ++i) myvector.push_back(i);   // 1 2 3 4 5 6 7 8 9
        // std::reverse(myvector.begin(),myvector.end());    // 9 8 7 6 5 4 3 2 1
        for (int i = 0; i < res.size(); i++)
            if (i % 2) reverse(res[i].begin(), res[i].end());

        return res;
    }
};
