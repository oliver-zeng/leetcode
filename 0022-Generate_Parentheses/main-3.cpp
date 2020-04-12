class Solution {
    struct Node {
        int left;
        int right;
        string tmp;
        Node(int l, int r, string str) : left(l), right(r), tmp(str) {}
    };
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        queue<Node> qe;
        qe.push(Node(n, n, ""));
        while (!qe.empty()) {
            Node cur = qe.front();
            qe.pop();
            if (cur.left == 0 && cur.right == 0) {
                res.push_back(cur.tmp);
                continue;
            }
            if (cur.left > 0)
                qe.push(Node(cur.left-1, cur.right, cur.tmp+"("));
            if (cur.right > 0 && cur.left < cur.right)
                qe.push(Node(cur.left, cur.right-1, cur.tmp+")"));
        }
        return res;
    }
};