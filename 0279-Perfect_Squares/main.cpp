class Solution {
private:
    vector<int>memo;
    int calcNum(int n) {
        if (n <= 0) return 0;
        if (memo[n] != INT_MAX) return memo[n];
        for (int i = 1; n - i * i >= 0; i++)
            memo[n] = min(1 + calcNum(n - i * i), memo[n]);
        return memo[n];
    }
    
public:
    int numSquares(int n) {
        // 背包容量为[0, n]
        memo = vector<int>(n+1, INT_MAX);
        return calcNum(n);
    }
};
