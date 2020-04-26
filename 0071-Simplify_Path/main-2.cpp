class Solution {
public:
    string simplifyPath(string path) {
        // 避免不以'/'结尾，导致最后一个内容拿不到
        // "/a//b////c/d//././/.."
        path += "/";
        int sz = path.size();
        int left = 0, right = 1;
        vector<string> vec;
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
                if (vec.size() != 0)
                    vec.pop_back();
                continue;
            } else
                vec.push_back(str);
        }
        // 如果为空也是有路径的，为"/"
        if (vec.empty())
            return "/";
        string res;
        for (auto elm : vec)
            res += "/" + elm;
        return res;
    }
};