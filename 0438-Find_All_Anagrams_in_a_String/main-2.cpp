class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        for (auto elm : p)
            need[elm]++;
        int left = 0, right = 0, match = 0;
        while (right < s.size()) {
            // 在滑块[left, right]中加入新right
            if (need.count(s[right])) {
                // window写在里面，只需要记录need里有的key就可以了
                window[s[right]]++;
                if (window[s[right]] == need[s[right]])
                    match++;
            }
            // 当滑块[left, right]的状态right已经足够时，开始找到left需要的位置
            while (match == need.size()) {
                if (right - left + 1 == p.size())
                    res.push_back(left);
                if (need.count(s[left])) {
                    window[s[left]]--;
                    if (window[s[left]] < need[s[left]])
                        match--;
                }
                left++;
            }
            // 最后当调整left后，使[left, right]不再满足时，重新移动right
            right++;
        }
        return res;
    }
};