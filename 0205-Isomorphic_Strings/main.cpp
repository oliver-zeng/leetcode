class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> record;
        map<char, char> rerecord;

        int sz = s.size();
        int tz = t.size();
        if (sz != tz) return false;
        // 下面的解是不行的，只能差出s不重复映射同一个值，但反向t的不行
        // 例如 s "ab" t "aa"，相当于在s里出现了，两个对到了1个的映射
        for (int i = 0; i < sz; i++) {
            if (record.find(s[i]) == record.end())
                record[s[i]] = t[i];
            else
                if (record[s[i]] != t[i])
                    return false;
        }
        // 所以后面还需要用得到的record从t推回到s才行
        // 牵扯到查找表，key与value的反向，除了pair是<int, int>能用数组以外
        // 就只能map倒map了
        for (auto elm : record)
            rerecord[elm.second] = elm.first;

        for (int i = 0; i < sz; i++)
            if (rerecord[t[i]] != s[i])
                return false;

        return true;
    }
};
