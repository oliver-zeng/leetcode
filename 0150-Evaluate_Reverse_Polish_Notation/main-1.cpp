class Solution {
private:
    bool isOperator(const string &str) {
        if (str != "+" &&
           str != "-" &&
           str != "*" &&
           str != "/")
            return false;
        else
            return true;
    }
    int doOperator(const string &op1, const string &op2, const string &op) {
        if (op == "+")
            return stoi(op1, 0, 10) + stoi(op2, 0, 10);
        else if (op == "-")
            return stoi(op1, 0, 10) - stoi(op2, 0, 10);
        else if (op == "*")
            return stoi(op1, 0, 10) * stoi(op2, 0, 10);
        else if (op == "/")
            return stoi(op1, 0, 10) / stoi(op2, 0, 10);
        throw invalid_argument("error");
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for (auto str : tokens) {
            if (isOperator(str)) {
                string op2 = st.top();
                st.pop();
                string op1 = st.top();
                st.pop();
                st.push(to_string(doOperator(op1, op2, str)));
            }
            else
                st.push(str);
        }
        return stoi(st.top(), 0, 10);
    }
};