class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s)
            freq[c]++;
        multimap<int, char> map;
        for (auto elm : freq)
            // multimap没有[]方法，只能用insert(make_pair(key, value))插入
            map.insert(make_pair(elm.second, elm.first));
        string res = "";
        // map底层实现是bst，所以顺序输出是升序，倒序输出是降序
        for (auto iter = map.rbegin(); iter != map.rend(); iter++)
            for (int i = 0; i < iter->first; i++)
                res += iter->second;
        return res;
    }
};