class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // 使用双查找表
        // 维护一个当前滑动窗口状态window，与need去做比对
        // 就不用每次拷贝一个新的need到函数中去做减法
        unordered_map<string, int> need;
        unordered_map<string, int> window;
        int match = 0;
        for (auto elm : words)
            need[elm]++;
        vector<int> res;
        if (words.size() == 0)
            return res;
        int len = words[0].size();
        int total = len * words.size();
        for (int i = 0; i + total - 1 < s.size(); i++) {
            // 这样写，没有left++减的过程，所以每次都要清零重新开始统计才行
            match = 0;
            window.clear();
            for (int left = i; left + len - 1 <= i + total - 1; left += len) {
                string str = s.substr(left, len);
                if (need.count(str) == 0)
                    break;
                window[str]++;
                if (window[str] == need[str])
                    match++;
            }
            if (match == need.size())
                res.push_back(i);
        }
        return res;
    }
};