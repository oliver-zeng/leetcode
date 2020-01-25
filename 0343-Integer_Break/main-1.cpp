class Solution {
private:
    vector<int> memo;
    // calcBreak(n)是把数字n分成两份的最大乘积
    // 所以不包括不将n分成两份的数字n本身
    int calcBreak(int n, vector<int> &memo) {
        if (1 == n) return 1;
        if (0 != memo[n]) return memo[n];
        int res = 0;
    	for (int i = 1; i < n; i++) {
            res = max(res, max(i * (n-i), i * calcBreak(n - i, memo)));
        }
        memo[n] = res;
    	return res;
    }
public:
    int integerBreak(int n) {
        // memo大小应该是 n + 1， 因为要满足n都能记录进去，且index与n对应
        memo = vector<int>(n+1, 0);
        memo[1] = 1;
        for ( int i = 2; i <= n; i++ ) {
            int res = 0;
        	for ( int j = 1; j < i; j++) {
                res = max(res, max(j * (i-j), j * memo[i - j]));
            }
            memo[i] = res;
        }
        return memo[n];
    }
};
