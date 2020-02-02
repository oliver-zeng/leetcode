class Solution {
public:
    void reverseString(vector<char>& s) {
        int sz = s.size();
        int l = 0, r = sz - 1;
        while(l < r) {
            swap(s[l++], s[r--]);
        }
    }
};
