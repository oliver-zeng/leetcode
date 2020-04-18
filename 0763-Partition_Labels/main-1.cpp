class Solution {
    void dfs(string &S, int begin, unordered_map<char, int> &map, vector<int> &res) {
        if (begin >= S.size())
            return;
        int end = map[S[begin]];
        int i = begin;
        while (i <= end) {
            if (map[S[i]] > end)
                end = map[S[i]];
            i++;
        }
        res.push_back(i - begin);
        dfs (S, i, map, res);
        return;
    }
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> map;
        for (int i = 0; i < S.size(); i++)
            map[S[i]] = i;
        vector<int> res;
        dfs(S, 0, map, res);
        return res;
    }
};