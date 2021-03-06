class Solution {
public:
    string minWindow(string s, string t) {
        int res_sz = INT_MAX;
        int res_left;

        unordered_map<char, int> goal;
        for (char c : t)
            goal[c]++;

        // 本题难点是解决：用 map size 去统计key中value
        // 原本map.size()只能统计字典里键值对出现的个数
        // 如果要统计计数，不仅要key能对上，每个key中value也要匹配上
        // 解决方法是再另一个查找表中引入变量match，只有当key与value都相同时才match++
        // 最后用match与目标表格中key个数去比即可
        unordered_map<char, int> window;
        int left, right, match;
        left = right = match = 0;
        for (; right < s.size(); right++) {
            // 只在window里统计goal中需要的char就够了
            if (goal.count(s[right])) {
                window[s[right]]++;
                if (window[s[right]] == goal[s[right]])
                    match++;
            }
            // 找到了就调整left，同时更新res
            while (match == goal.size()) {
                if (right - left + 1 < res_sz) {
                    // substr需要的两个参数是 起始点left & [left, right]区间元素个数
                    res_left = left;
                    res_sz = right - left + 1;
                }
                // cont & find
                // 使用count，返回的是被查找键为key的键值对个数。非multi不存在相同key，返回值只能是1或0。
                // 使用find，返回的是被查找元素的位置，没有则返回map.end()
                // 所以如果只是想看有没有，而不是找到位置进行操作的话，用cont更简洁
                if (goal.count(s[left])) {
                    window[s[left]]--;
                    // 只有真的小于goal了，才是match要减的时候
                    if (window[s[left]] < goal[s[left]])
                        match--;
                }
                left++;
            }
        }

        if (res_sz == INT_MAX)
            return "";
        return s.substr(res_left, res_sz);
    }
};