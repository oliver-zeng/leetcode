class Solution {
private:
    // 二维平面上的遍历
    // 首先要准备原点(x, y)朝上右下左4个方向移动需要加的向量坐标
    vector<vector<int>> direct = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    // 以及判断坐标是否越界的函数
    bool inArea(int i, int j, int row, int col) {
        return i >= 0 && i < row && j >= 0 && j < col;
    }

    void dfs(vector<vector<int>> &matrix, vector<vector<int>> &visit, int i, int j) {
        if (visit[i][j])
            return;

        visit[i][j] = true;
        int row = matrix.size();
        int col = matrix[0].size();
        for (int k = 0; k < 4; k++) {
            int x = i + direct[k][0];
            int y = j + direct[k][1];
            if (inArea(x, y, row, col) && matrix[x][y] >= matrix[i][j])
                dfs(matrix, visit, x, y);
        }

        return;
    }

public:
    // 本题对矩阵中每个点进行dfs，判断最终是否到达 太平洋 & 大西洋 边界，很麻烦
    // 换一种思维方式，分别从 太平洋 & 大西洋 边界位置出发遍历，逆流进行搜索
    // 用两个二维数组进行记录，能同时被它们两遍历到的，就是答案
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {

        // 二维矩阵必须在一维不为空时，才能访问二维
        // 这里必须在row不为0时，才有matrix[0]，才能看col大小
        int row = matrix.size();
        if (row == 0)
            return {};
        int col = matrix[0].size();

        // 两个矩阵分别记录可以流向Pacific & Atlantic的点
        vector<vector<int>> Pacific(vector<vector<int>>(row, vector<int>(col, false)));
        vector<vector<int>> Atlantic(vector<vector<int>>(row, vector<int>(col, false)));

        // 分别从四个边出发，进行四个方向的dfs
        // 太平洋是每行第一个，大西洋是每行最后一个
        for (int i = 0; i < row; i++) {
            dfs(matrix, Pacific, i, 0);
            dfs(matrix, Atlantic, i, col - 1);
        }
        // 太平洋是每列第一个，大西洋是每列最后一个
        for (int j = 0; j < col; j++) {
            dfs(matrix, Pacific, 0, j);
            dfs(matrix, Atlantic, row - 1, j);
        }

        // 将两边都能流入的点，记录到返回值里
        vector<vector<int>> res;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++) {
                if (Pacific[i][j] && Atlantic[i][j])
                    // res.push_back(vector<int>({i, j}));
                    // 写成下面就可以了
                    res.push_back({i, j});
            }

        return res;
    }
};