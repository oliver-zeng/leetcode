#define USE_AND
class Solution {
public:
    string longestPalindrome(string s) {
        // 连续子串&回文，都是dp的天然培养皿
        // 因为当中包含了大量已计算过的内容
        // 只需要在原有串的基础上，稍作修改就可以得到新的串
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        string res = "";
        for (int len = 1; len <= n; len ++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                if (len == 1) {
                    dp[i][j] = 1;
                } else if (len == 2) {
                    dp[i][j] = (s[i] == s[j]) ? 2 : 0;
#ifdef USE_AND
                } else {
                    // &&运算实际上是特殊的加法运算：
                    // 在每一项不为0时，把它们的值加起来
                    // 若有一项为0，值就为0，并立刻结束运算，&&后面的项将根本不会执行
                    dp[i][j] = dp[i+1][j-1] && s[i] == s[j];
                }
#else
                } else if (dp[i+1][j-1] && s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 1;
                } else {
                    dp[i][j] = 0;
                }
#endif
                // 这里得是dp[i][j]不为0才看长度
                if (dp[i][j] && len > res.size())
                	res = s.substr(i, len);
            }
        }
        return res;
    }
};