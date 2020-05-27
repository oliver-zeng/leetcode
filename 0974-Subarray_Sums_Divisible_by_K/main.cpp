// 一看到“子数组和”，有必要马上想到“前缀和”
// sum [i+1, j] = sum [0, j] - sum [0, i]
// 但这里dp存放的是通过前缀和计算出来的 mod K 的值
// sum [i+1, j] % k == 0 => sum [0, j] % K == sum [0, i] % K => dp[i] == dp[j]
// 但这里的和是可以为负值的，所以 mod K 也是负值，实际上负值与正值也可以满足条件
// 举例：K = 4，求得一个前缀和为 -1 ， -1 % K = -1 ，3 % K = 3
// 它们前缀和之差：3 - (-1) 为 4 。 4 % K = 0
// 也可以满足条件，所以负模，要加上 K ，转成正数
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int sz = A.size();
        vector<int> dp(sz);
        int sum = 0;
        for (int i = 0; i < sz; i++) {
            sum += A[i];
            dp[i] = sum % K < 0 ? sum % K + K : sum % K;
        }
        unordered_map<int, int> dict;
        for (auto elm : dp)
            dict[elm]++;
        int res = 0;
        // 统计[i, j]成立组成的组合（i != j），从可以的点中任意选取两个
        for (auto elm : dict) {
            if (elm.second < 2)
                continue;
            res += elm.second * (elm.second - 1) / 2;
        }
        // 统计[i]一个点成立的组合
        res += dict[0];
        return res;
    }
};