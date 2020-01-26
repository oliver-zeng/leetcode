class Solution {
private:
    int sz;
    vector<int> memo;
    vector<int> cost_0;
    vector<int> cost_1;
    int calcMax(vector<string>& strs, int index, int m, int n) {
        if (index >= sz) return 0;
        int res = 0;
        for (int i = index; i < sz; i++) {
            res = ((cost_0[index] < m) && (cost_1[index] < n)) ?
                max(1 + calcMax(strs, index + 1, m - cost_0[index], n - cost_1[index]), calcMax(strs, index + 1, m, n)) : calcMax(strs, index + 1, m, n);
        }
        return res;
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // 背包组合问题，在不超过m个0，n个1的情况下，在strs中选最多item
        // 考虑item i选，与不选，对结果与消耗的影响
        sz = strs.size();
        memo = vector<int>(sz, -1);
        cost_0 = vector<int>(sz, 0);
        cost_1 = vector<int>(sz, 0);
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < strs[i].size(); j++) {
                if (strs[i][j] == '0')
                    cost_0[i]++;
                else
                    cost_1[i]++;
            }
        }
        return calcMax(strs, 0, m, n);
    }
};
