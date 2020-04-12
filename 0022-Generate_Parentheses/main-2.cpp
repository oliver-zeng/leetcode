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
        stack<Node> st;
        st.push(Node(n, n, ""));
        while (!st.empty()) {
            Node cur = st.top();
            st.pop();
            if (cur.left == 0 && cur.right == 0) {
                res.push_back(cur.tmp);
                continue;
            }
            if (cur.left > 0)
                st.push(Node(cur.left-1, cur.right, cur.tmp+"("));
            if (cur.right > 0 && cur.left < cur.right)
                st.push(Node(cur.left, cur.right-1, cur.tmp+")"));
        }
        return res;
    }
};