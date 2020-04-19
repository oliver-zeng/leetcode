class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int res = -1;
        int row = grid.size();
        if (row == 0) return 0;
        int col = grid[0].size();
        if (col == 0) return 0;
        queue<pair<int, int>> qe;
        // 不能直接在grid中存储答案的情况，就只能专门申请一个与grid等大小的distance来存储了
        vector<vector<int>> distance(row, vector<int>(col));
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (grid[i][j] == 1)
                    qe.push(make_pair(i, j));
                else
                    distance[i][j] = -1;
        int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!qe.empty()) {
            int x = qe.front().first;
            int y = qe.front().second;
            qe.pop();
            for (int i = 0; i < 4; i++) {
                int newx = x + d[i][0];
                int newy = y + d[i][1];
                if (newx >= 0 && newx < row && newy >= 0 && newy < col && distance[newx][newy] == -1) {
                    distance[newx][newy] = distance[x][y] + 1;
                    res = max(res, distance[newx][newy]);
                    qe.push(make_pair(newx, newy));
                }
            }
        }
        return res;
    }
};