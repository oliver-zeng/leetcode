class Solution {
public:
    int calPoints(vector<string>& ops) {
        // 这题的要点是：
        // "+" "D" "Integer"
        // 每一项操作都会基于stack中记录的每轮分数再计算一个新值去push
        // 只有"C"是会pop出一个值
        int res = 0;
        stack<int> st; // only store integer
        for (auto elm : ops) {
            if (elm == "C") {
                res -= st.top();
                st.pop();
            } else if (elm == "D") {
                int tmp = 2 * st.top();
                st.push(tmp);
                res += tmp;
            } else if (elm == "+") {
                int t1 = st.top();
                st.pop();
                int t2 = st.top();
                st.push(t1);
                st.push(t1+t2);
                res += t1 + t2;
            } else {
                st.push(stoi(elm, NULL, 10));
                res += st.top();
            }
        }
        return res;
    }
};