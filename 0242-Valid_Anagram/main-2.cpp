class Solution {
public:
    bool isAnagram(string s, string t) {
        // 可以提前判断，确保长度相等，就可以用match来判断同字母异序词了
        if (s.size() != t.size())
            return false;
        unordered_map<char, int> need, window;
        int match = 0;
        for (char c : s)
            need[c]++;
        for (char c : t) {
            window[c]++;
            // 必须s与t长度相同时才能这么判断
            // 否则s = "anagram", t = "nagaramm"
            // window比need中同key的value大，那用match来比就是错误的
            if (window[c] == need[c])
                match++;
        }
        if (match == need.size())
            return true;
        return false;
    }
};