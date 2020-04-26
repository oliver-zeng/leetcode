class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto elm : tokens) {
            if (elm != "+" && elm != "*" && elm != "/" && elm != "-") {
                st.push(stoi(elm, NULL, 10));
                continue;
            }
            long long n1 = st.top();
            st.pop();
            long long n2 = st.top();
            st.pop();
            if (elm == "+")
                st.push((int)(n2 + n1));
            else if (elm == "-")
                st.push((int)(n2 - n1));
            else if (elm == "*")
                st.push((int)(n2 * n1));
            else if (elm == "/")
                st.push((int)(n2 / n1));
        }
        if (st.empty())
            return 0;
        return st.top();
    }
};