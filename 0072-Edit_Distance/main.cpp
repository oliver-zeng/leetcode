class Solution {
public:
    int minDistance(string word1, string word2) {
        int sz1 = word1.size(), sz2 = word2.size();
        vector<vector<int>> dp(sz1+1, vector<int>(sz2+1));
        for (int i = 0; i <= sz1; i++)
            dp[i][0] = i;
        for (int j = 0; j <= sz2; j++)
            dp[0][j] = j;
        for (int i = 1; i <= sz1; i++)
            for (int j = 1; j <= sz2; j++) {
                if (word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i][j-1]+1, min(dp[i-1][j]+1, dp[i-1][j-1]+1));
            }
        return dp[sz1][sz2];
    }
};