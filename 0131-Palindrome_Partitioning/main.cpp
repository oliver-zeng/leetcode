class Solution {
private:
    vector<vector<string>> res;
    vector<string> tmp;
    bool palindrome (string &s) {
        int sz = s.size();
        stack<char> st;
        int i = 0;
        for (; i < sz/2; i++)
            st.push(s[i]);
        if (sz % 2)
            i++;
        while (!st.empty()) {
            if (st.top() != s[i++])
                return false;
            st.pop();
        }
        return true;
    }
    void dfs (string &s, int left) {
        if (left == s.size()) {
            res.push_back(tmp);
            return;
        }
        for (int sz = 1; left + sz <= s.size(); sz++) {
            string str = s.substr(left, sz);
            if (palindrome(str)) {
                tmp.push_back(str);
                dfs (s, left + sz);
                tmp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        dfs (s, 0);
        return res;
    }
};