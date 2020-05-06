class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> map;
        // 此模板是[left, right)的滑块
        int left = 0, right = 0, res = 0;
        while (right < s.size()) {
            // left++一次不一定能让right重新满足，所以用while
            while (map.count(s[right]))
                map.erase(s[left++]);
            map.insert(s[right++]);
            res = max(res, right - left);
        }
        return res;
    }
};