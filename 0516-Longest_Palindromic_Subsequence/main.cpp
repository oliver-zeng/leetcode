class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int sz = s.size();
        vector<vector<int>> dp(sz, vector<int>(sz));
        for (int i = 0; i < sz; i++)
            dp[i][i] = 1;
        for (int i = 0; i < sz; i++)
            for (int j = 0; j < i; j++)
                dp[i][j] = 0;
        for (int i = sz; i >= 0; i--)
            for (int j = i + 1; j < sz; j++) {
                if (s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1] + 2;
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        return dp[0][sz-1];
    }
};