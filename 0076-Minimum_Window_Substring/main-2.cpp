class Solution {
public:
    string minWindow(string s, string t) {
        int res = INT_MAX;
        vector<int> resIndex;
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        for (auto elm : t)
            need[elm]++;
        // 如果要统计计数，不仅要key能对上，每个key中value也要匹配上
        // 解决方法是再另一个查找表中引入变量match，只有当key与value都相同时才match++
        // 最后用match与目标表格中key个数去比即可
        int left = 0, right = 0, match = 0;
        while (right < s.size()) {
            if (need.count(s[right])) {
                window[s[right]]++;
                // Match数量匹配上了，match++
                // 再匹配上了match不会加加但也不会减
                // 所以最终在满足时的window是大于等于需求量的
                if (window[s[right]] == need[s[right]])
                    match++;
            }
            // 滑动窗口都满足超额完成后，再回头减，找最优
            // 此时不断移动Left，若还满足，就缩减窗口，记录最优解
            // 直至left不满足后，right重新开始移动
            while (match == need.size()) {
                if (res > right - left + 1) {
                    res = right - left + 1;
                    resIndex = {left, right};
                }
                if (need.count(s[left])) {
                    window[s[left]]--;
                    if (window[s[left]] < need[s[left]])
                        match--;
                }
                // while里可以跳出的index移动，一定要在while的结束，写在条件里永远执行不到的话，就死循环了
                left++;
            }
            right++;
        }
        // 用vector记录答案，返回vector索引的时候，若没有答案，vector为空要特判，否则访问索引会挂掉
        if (resIndex.size() == 0)
            return "";
        return s.substr(resIndex[0], resIndex[1]-resIndex[0]+1);
    }
};