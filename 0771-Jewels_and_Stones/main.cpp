class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> map;
        for (auto elm : J)
            map.insert(elm);
        int res = 0;
        for (auto elm : S) {
            if (map.find(elm) == map.end())
                continue;
            res++;
        }
        return res;
    }
};