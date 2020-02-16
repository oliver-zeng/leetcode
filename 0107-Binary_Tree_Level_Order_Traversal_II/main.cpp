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
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        // 用pair记录node所在层的level
        queue<pair<TreeNode*, int>> que;
        vector<vector<int>> res;
        // 如果root不存在，就不用将root入队了
        if (!root) return res;
        que.push(make_pair(root, 0));
        while(!que.empty()) {
            // 先接到front()里的数据，再pop()
            TreeNode *p = que.front().first;
            int level = que.front().second;
            que.pop();
            // res范围是[0, size)，当level = size时达到开区间，需要再申请一个
            if (level == res.size())
                // 建一个空的vector，后面就可以用res[level].push_back()了
                res.push_back(vector<int>());
            res[level].push_back(p->val);
            if (p->left) que.push(make_pair(p->left, level+1));
            if (p->right) que.push(make_pair(p->right, level+1));
        }
        // std::revers(iter_begin, iter_end)可以将容器逆置
        reverse(res.begin(), res.end());
        return res;
    }
};
