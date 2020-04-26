class Solution {
public:
    string simplifyPath(string path) {
        // 避免不以'/'结尾，导致最后一个内容拿不到
        // "/a//b////c/d//././/.."
        path += "/";
        int sz = path.size();
        int left = 0, right = 1;
        stack<string> st;
        while (right < sz) {
            if (path[right] != '/') {
                right++;
                continue;
            }
            string str = path.substr(left+1, right - left - 1);
            left = right;
            right++;
            if (str == "." || str == "")
                continue;
            // 这里st.empty()必须写在里面，否则"/../"会算作else，走进else push进st
            else if (str == "..") {
                if (!st.empty())
                    st.pop();
                continue;
            } else
                st.push(str);
        }
        // 如果为空也是有路径的，为"/"
        if (st.empty())
            return "/";
        string res;
        while (!st.empty()) {
            // 每次拼接一个新的串，前段是要拼接的新内容，后段是之前的串，这样就变成了往前插
            res = "/" + st.top() + res;
            st.pop();
        }
        return res;
    }
};