class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 这题的精髓在于，除了需要知道node指针以外，还需要知道该节点所在的层数
        // 如果把node再封装到一个结构里是不现实的
        // 但开两个queue，一个记录node，一个同步记录层数又很浪费，且sync不好非常容易出错
        // 所以这个时候用pair在不使用结构体嵌套的同时，又可以将不同结构的成员绑定到一起
        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> res;
        q.push(make_pair(root, 0));
        while(!q.empty()) {
            // 先把数据解绑拿出来
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();
            // 再对数据进行处理
            if (node) {
                // 若树深与res行数相同时，需要增加新行
                if (level == res.size())
                    // 二维数组加空行的方法，调用空构造函数
                    res.push_back(vector<int>());
                res[level].push_back(node->val);
                q.push(make_pair(node->left, level+1));
                q.push(make_pair(node->right, level+1));
            }
        }
        return res;
    }
};
