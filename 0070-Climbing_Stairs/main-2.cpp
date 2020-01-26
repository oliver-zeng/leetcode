class Solution {
public:
    int climbStairs(int n) {
        if (1 == n) return 1;
        if (2 == n) return 2;
        // f(n) = f(n-1) + f(n-2)
        // mini positive integer is 1
        // n - 2 = 1 => n = 3
        // need initialize f(2) & f(1)
        vector<int> memo(n+1, 0);
        memo[1] = 1;
        memo[2] = 2;
        for (int i = 3; i <= n; i++) {
            memo[i] = memo[i-1] + memo[i-2];
        }
        return memo[n];
    }
};
