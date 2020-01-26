class Solution {
private:
    vector<vector<int>> memo;
    int calcNum(int m, int n) {
        if (m == 1 && n == 1) return 1;
        if (m < 1 || n < 1) return 0;
        if (memo[m][n] != -1) return memo[m][n];
        memo[m][n] = calcNum(m - 1, n) + calcNum(m, n - 1);
        return memo[m][n];
    }
public:
    int uniquePaths(int m, int n) {
        memo = vector<vector<int>>(m + 1, vector<int>(n + 1, -1));
        return calcNum(m, n);
    }
};
