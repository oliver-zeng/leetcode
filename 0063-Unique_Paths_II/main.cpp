class Solution {
private:
    vector<vector<int>> memo;
    int calcNum(int m, int n, vector<vector<int>>& obstacleGrid) {
        // memo越界
        if (m < 0 || n < 0) return 0;
        
        if (memo[m][n] != -1) return memo[m][n];
        memo[m][n] = (obstacleGrid[m-1][n] ? 0 : calcNum(m-1, n, obstacleGrid))
            + (obstacleGrid[m][n-1] ? 0 : calcNum(m, n-1, obstacleGrid));
        return memo[m][n];
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        memo = vector<vector<int>>(m, vector<int>(n, -1));
        // start obstacle
        if (obstacleGrid[0][0]) return 0;
        // memo赋初值
        memo[0][0] = obstacleGrid[m-1][n-1] ? 0 : 1;
        for(int j = 1; j < n; j ++)
            if(obstacleGrid[0][j])
                memo[0][j] = 0;
            else
                memo[0][j] = memo[0][j - 1];
        for(int i = 1; i < m; i ++)
            if(obstacleGrid[i][0])
                memo[i][0] = 0;
            else
                memo[i][0] = memo[i - 1][0];
        return calcNum(m-1, n-1, obstacleGrid);
    }
};
