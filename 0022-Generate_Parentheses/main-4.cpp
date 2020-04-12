class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n+1, vector<string>());
        // 0对括号，组合是""
        dp[0].push_back("");
        // i对括号的所有组合，可以用j的所有可能，使得：
        // 1对括号包上j对括号，再加上剩余i-j-1对括号得到
        // dp[i] = "(" + dp[j] + ")" + dp[i- j - 1]
        // 尝试所有把i分成两部分的组合，就是分割选择需要用到两层循环
        // 这里分割选择包括不分割，若不包括，要对不分割进行单独处理
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                // dp[j]与dp[i-j-1]的答案是vector，所以要遍历所有的答案
                for (auto str1 : dp[j])
                    for (auto str2 : dp[i-j-1])
                        dp[i].push_back("(" + str1 + ")" + str2);
            }
        }
        return dp[n];
    }
};