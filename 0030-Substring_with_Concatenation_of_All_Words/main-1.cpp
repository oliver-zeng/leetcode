class Solution {
    bool isAns(string &s, unordered_map<string, int> record, int left, int right, int len) {
        // 分割成无数等长子串，结束条件是子串右边界不越界
        for (int i = left; i + len - 1 <= right; i += len) {
            if (record[s.substr(left, len)] == 0)
                return false;
            record[s.substr(left, len)]--;
            // 别忘了子串左边界向前移动
            left += len;
        }
        cout << s.substr(left, right - left + 1) << endl;
        return true;
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // 统计用没用到，只能用map来做，不能用vector
        // 因为vector只能查找存不存在，但是没法记录存在个数，与使用个数
        // 也没法用vector<bool> used来辅助，因为find找到的返回值是iter根本没法知道对应vector的index，因此必须要用map
        unordered_map<string, int> record;
        for (auto elm : words)
            record[elm]++;
        vector<int> res;
        unsigned int sz = words.size();
        if (sz == 0)
            return res;
        unsigned int len = words[0].size();
        unsigned int total = sz * len;
        int left = 0, right = total - 1;
        while (right < s.size()) {
            if (isAns(s, record, left, right, len))
                res.push_back(left);
            left++;
            right++;
        }
        return res;
    }
};