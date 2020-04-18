class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> map;
        for (int i = 0; i < S.size(); i++)
            map[S[i]] = i;
        vector<int> res;
        int left = 0;
        // 用 while 的两种情形：
        // 1. index 在循环外，还要使用的情形
        // 2. index 不是按固定方式移动（i++、i+=i..)，而是直接更新值的情形
        while (left < S.size()) {
            int i = left;
            int right = map[S[i]];
            while (i <= right) {
                right = max(right, map[S[i]]);
                i++;
            }
            res.push_back(i - left);
            left = i;
        }
        return res;
    }
};