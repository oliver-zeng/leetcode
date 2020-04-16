class Solution {
    int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &used, int x, int y) {
        for (int i = 0; i < 4; i++) {
            int newx = x + d[i][0];
            int newy = y + d[i][1];
            if ((newx >= 0 && newx < grid.size()) &&
                (newy >= 0 && newy < grid[0].size()) &&
                !used[newx][newy] && grid[newx][newy] == '1') {
                used[newx][newy] = true;
                dfs(grid, used, newx, newy);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        // 二维定义sop，要用变量，不能直接带进去
        // vector<vector<bool>> used(grid.size(), vector<int>(grid[0].size(), false));
        int row = grid.size();
        if (row == 0) return 0;
        int col = grid[0].size();
        vector<vector<bool>> used(row, vector<bool>(col, false));
        
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == '1' && !used[i][j]) {
                    res++;
                    dfs(grid, used, i, j);
                }
        return res;
    }
};