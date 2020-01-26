class Solution {
private:
    vector<vector<int>> memo;
    int row;
    int col;
    int calcNum(int m, int n, vector<vector<int>>& grid) {
        if (m < 1 || n < 1) return 0;
        if (memo[m][n] != -1) return memo[m][n];
        return memo[m][n] = min(calcNum(m - 1, n, grid), calcNum(m, n - 1, grid)) + grid[row-m][col-n];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        memo = vector<vector<int>>(row+1, vector<int>(col+1, -1));
        memo[1][1] = grid[row - 1][col - 1];
        for (int i = 2; i <= row; i++)
            memo[i][1] = memo[i - 1][1] + grid[row - i][col-1];
        for (int i = 2; i <= col; i++)
            memo[1][i] = memo[1][i - 1] + grid[row-1][col - i];
        return calcNum(row, col, grid);
    }
};
