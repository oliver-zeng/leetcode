class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> dict;
        for (string str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            dict[tmp].push_back(str);
        }
        vector<vector<string>> res;
        for (auto iter = dict.begin(); iter != dict.end(); iter++) {
            res.push_back(vector<string>());
            for (string str : iter->second)
                res[res.size()-1].push_back(str);
        }
        return res;
    }
};