class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sz = s.size();
        vector<int> used(26, 0);
        for (auto elm : p)
            used[elm - 'a']++;
        vector<int> res;
        int l = 0, r = -1;
        while (l < sz) {
            if ((r + 1 < sz) && (used[s[r+1] - 'a'])) {
                used[s[++r] - 'a']--;
            } else {
                // 只有前++需要提前判断，防止数组越界
                // 后++是在数组操作完成后，才会去自增，就不会越界了
                used[s[l++] - 'a']++;
            }
            if (r - l + 1 == p.size())
                res.push_back(l);
        }
        return res;
    }
};
