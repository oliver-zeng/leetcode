class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        for (auto elm : s1)
            need[elm]++;
        int left = 0, right = 0, match = 0;
        while (right < s2.size()) {
            // 注意这里必须先用 need.count 判断后 unorder_map 才能使用
            // 否则need[s2[right]]会出现need中没有的key，加大need中key的数量
            if (need.count(s2[right])) {
                window[s2[right]]++;
                if (window[s2[right]] == need[s2[right]])
                    match++;
            }
#if 0 // 错误答案
            // while条件互换就不对了
            // 还没有达到滑块要求就判断，若没有return true，后面调整left的操作就是错的了
            while (right - left + 1 == s1.size()) {
                // 后面判断 match == need.size() 就不对了
                if (match == need.size())
                    return true;
                if (need.count(s2[left])) {
                    window[s2[left]]--;
                    if (window[s2[left]] < need[s2[left]])
                        match--;
                }
                left++;
            }
#else
            // 必须在滑块满足后，再开始看是不是要的解，调整left
            while (match == need.size()) {
                if (right - left + 1 == s1.size())
                    return true;
                 if (need.count(s2[left])) {
                    window[s2[left]]--;
                    if (window[s2[left]] < need[s2[left]])
                        match--;
                }
                left++;
            }
#endif
            right++;
        }
        return false;
    }
};