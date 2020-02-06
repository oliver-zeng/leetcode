class Solution {
public:
    bool isValid(string s) {
        stack<char> record;
        int sz = s.size();
        for (int i = 0; i < sz; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                record.push(s[i]);
            else {
                // stack基本操作
                // push进栈，pop出栈（并不返回栈顶元素），top访问栈顶元素
                if (record.empty())
                    return false;
                char c = record.top();
                if ((c == '(') && (s[i] != ')'))
                    return false;
                if ((c == '[') && (s[i] != ']'))
                    return false;
                if ((c == '{') && (s[i] != '}'))
                    return false;
                record.pop();
            }
        }
        // 还要做最后一次判空，避免是"["这种情况
        if (record.empty())
            return true;
        else
            return false;
    }
};
