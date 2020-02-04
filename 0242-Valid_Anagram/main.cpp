class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> record;
        int sz = s.size();
        if (sz == 0)
            return true;
        if (sz != t.size())
            return false;

        for (int i = 0; i < sz; i++)
            record[s[i]]++;

        for (int i = 0; i < sz; i++)
            if ((record[t[i]]--) == 0)
                return false;

        return true;
    }
};
