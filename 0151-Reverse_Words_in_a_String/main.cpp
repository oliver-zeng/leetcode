class Solution {
public:
    string reverseWords(string s) {
        if (s.size() == 0)
            return "";
        stack<string> st;
        for (int i = 0; i < s.size();) {
            if (s[i] == ' ') {
                i++;
                continue;
            }
            int end = i;
            while (end < s.size() && s[end] != ' ')
                end++;
            end--;
            st.push(s.substr(i, end - i + 1));
            i = end + 1;
        }
        string res = "";
        while (!st.empty()) {
            res += st.top() + " ";
            st.pop();
        }
        // for intput is " "
        if (res.size() != 0)
            res.pop_back();
        return res;
    }
};