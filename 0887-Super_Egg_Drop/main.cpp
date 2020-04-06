class Solution {
public:
    int superEggDrop(int K, int N) {
        if (K == 1)
            return N;
        if (N == 1)
            return 1;
        vector<vector<int>> dp(K + 1, vector<int>(N + 1));
        // 只有1次操作，只要蛋数不为0，就都只能确定1层楼的高度
        for (int i = 1; i <= K; i++)
            dp[i][1] = 1;
        // 只有1个蛋，有多少次操作，就能确定多高的楼
        for (int m = 1; m <= N; m++)
            dp[1][m] = m;
        // 这里把 m 放在最外层，是为了找到最小的 m 值
        // 小于号当跳出循环时，正好就是在等于 N 的最小m
        int m = 2;
        for (; m <= N; m++)
            for (int i = 2; i <= K; i++) {
                dp[i][m] = dp[i - 1][m - 1] + 1 + dp[i][m - 1];
                //cout << "dp["<< i << "][" << m << "] " << dp[i][m] << endl;
                if (dp[K][m] >= N)
                    return m;
            }
                
        return -1;
    }
};