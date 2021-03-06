class Solution {
private:
    int row, col;
    int direct[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool inArea(int i, int j) {
        return i >= 0 && i < row && j >= 0 && j < col;
    }
    void dfs(vector<vector<char>>& board, int i, int j) {
        board[i][j] = '#';
        for (int d = 0; d < 4; d++) {
            int x = i + direct[d][0];
            int y = j + direct[d][1];
            if (inArea(x, y) && board[x][y] == 'O')
                dfs(board, x, y);
        }
        return;
    }
public:
    void solve(vector<vector<char>>& board) {
        // 获取二维vector行列的标准写法
        row = board.size();
        if (row == 0)
            return;
        col = board[0].size();
        if (col == 0)
            return;
        // 四条边上为'O'的点，将其转为临时字符'#'
        for (int i = 0; i < row; i++) {
            if (board[i][0] == 'O')
                dfs(board, i, 0);
            if (board[i][col - 1] == 'O')
                dfs(board, i, col - 1);
        }
        for (int j = 0; j < col; j++) {
            if (board[0][j] == 'O')
                dfs(board, 0, j);
            if (board[row - 1][j] == 'O')
                dfs(board, row - 1, j);
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