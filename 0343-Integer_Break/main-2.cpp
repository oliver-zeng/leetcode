class Solution {
public:
    int integerBreak(int n) {
        // memo大小应该是 n + 1， 因为要满足n都能记录进去，且index与n对应
        vector<int> memo(n+1, 0);
        memo[1] = 1;
        // i是memo索引
        for ( int i = 2; i <= n; i++ ) {
            int res = 0;
            // j是将i拆分成两部分的其中一部分
        	for ( int j = 1; j < i; j++) {
                res = max(res, max(j * (i-j), j * memo[i - j]));
            }
            memo[i] = res;
        }
        return memo[n];
    }
};
