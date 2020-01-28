// 参考leetcode 79
// 像洪水泛滥一样的填充算法
// floodfill算法-实质上是深度优先遍历dfs算法
class Solution {
private:
    int row, col;
    int count;
    vector<vector<bool>> used;
    vector<vector<char>> array;
    int d[4][2] = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
    bool inArea(int x, int y) {
        if ((x >= 0) && (x < row) && (y >= 0) && (y < col))
            return true;
        else
            return false;
    }
    void calcIslands(int x, int y) {
        for (int i = 0; i < 4; i++) {
            int newx = x + d[i][0];
            int newy = y + d[i][1];
            if (inArea(newx, newy) && !used[newx][newy] && (array[x][y] == '1')) {
                used[newx][newy] = true;
                calcIslands(newx, newy);
            }
        }
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        array = grid;
        row = grid.size();
        if (row == 0) return 0;
        col = grid[0].size();
        used = vector<vector<bool>>(row, vector<bool>(col, false));
        count = 0;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++) {
                if (!used[i][j] && (array[i][j] == '1')) count++;
                calcIslands(i, j);
            }
        return count;
    }
};
