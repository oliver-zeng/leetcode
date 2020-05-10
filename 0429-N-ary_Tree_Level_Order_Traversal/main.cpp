/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<pair<Node*, int>> qe;
        // 一定记住要在首元素存在时才放入
        if (root)
            qe.push(make_pair(root, 0));
        while (!qe.empty()) {
            Node* tmp = qe.front().first;
            int level = qe.front().second;
            qe.pop();
            if (level == res.size())
                res.push_back(vector<int>());
            res[level].push_back(tmp->val);
            for (Node* elm : tmp->children)
                qe.push(make_pair(elm, level+1));
        }
        return res;
    }
};