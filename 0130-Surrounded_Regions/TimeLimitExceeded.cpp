class Solution {
private:
    int row, col;
    int direct[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool inArea(int i, int j) {
        return i >= 0 && i < row && j >= 0 && j < col;
    }
    // 需要弄明白dfs与bfs的时间复杂度分析
    // 对于只是要求遍历完所有点的case，能用dfs解的就能用bfs解
    // 因为都是把相邻的点，按照一定顺序，dfs或bfs逐一遍历到而已
    // 由非递归的dfs改写成非递归的bfs非常简单
    // 只要把存储结构由dfs的stack换成bfs的queue就够了
    void bfs(vector<vector<char>>& board, int i, int j) {
        queue<pair<int, int>> qe;
        vector<vector<bool>> visit = vector<vector<bool>>(row, vector<bool>(col , false));
        qe.push(make_pair(i, j));
        while (!qe.empty()) {
            int cx = qe.front().first;
            int cy = qe.front().second;
            visit[cx][cy] = true;
            board[cx][cy] = '#';
            qe.pop();
            for (int d = 0; d < 4; d++) {
                int x = cx + direct[d][0];
                int y = cy + direct[d][1];
                if (inArea(x, y) && !visit[x][y] && board[x][y] == 'O')
                    qe.push(make_pair(x, y));
            }
        }

        return;
    }
public:
    void solve(vector<vector<char>>& board) {
        // 获取二维vector行列的标准写法
        row = board.size();
        if (row == 0) return;
        col = board[0].size();
        if (col == 0) return;
        // 四条边上为'O'的点，将其转为临时字符'#'
        for (int i = 0; i < row; i++) {
            if (board[i][0] == 'O')
                bfs(board, i, 0);
            if (board[i][col - 1] == 'O')
                bfs(board, i, col - 1);
        }
        for (int j = 0; j < col; j++) {
            if (board[0][j] == 'O')
                bfs(board, 0, j);
            if (board[row - 1][j] == 'O')
                bfs(board, row - 1, j);
        }
        // 将不与四边相连的'O'涂为'X'
        // 与四边相连的'O'，由'#'改回'O'
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
         return;  
    }
};