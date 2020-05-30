class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int sz_a = A.size();
        int sz_b = B.size();
        vector<vector<int>> dp(sz_a + 1, vector<int>(sz_b + 1, 0));
        int res = 0;
        for (int i = 1; i <= sz_a; i++)
            for (int j = 1; j <= sz_b; j++) {
                if (A[i-1] == B[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                //res = max(dp[i][j], res); 不用函数能快一点
                res = dp[i][j] > res ? dp[i][j] : res;
            }
        return res;
    }
};