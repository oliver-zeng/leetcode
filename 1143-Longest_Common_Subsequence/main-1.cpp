class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // 子序列类型的问题，穷举出所有可能性能差，而动态规划算法做的就是穷举 + 剪枝
        // 因此只要涉及子序列问题，十有八九都需要动态规划来解决，往这方面考虑就对了
        int sz1 = text1.size();
        int sz2 = text2.size();
        // dp[i][j] 的含义是：对于 s1[1..i] 和 s2[1..j]，它们的 LCS 长度是 dp[i][j]。
        // 注意这里不是以s1[i]与s2[j]结尾的最优解，而是s1[1..i]与s2[1..j]中任意子串的最优解
        vector<vector<int>> dp(sz1+1, vector<int>(sz2+1, 0));
        for (int i = 1; i <= sz1; i++)
            for (int j = 1; j <= sz2; j++) {
                // 如果 s1[i]==s2[j]，那么这个字符一定在 lcs 中
                if (text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else // 否则的话，s1[i] 和 s2[j] 这两个字符至少有一个不在 lcs 中
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        return dp[sz1][sz2];
    }
};