class Solution {
private:

    vector<vector<bool>> row;
    vector<vector<bool>> col;
    vector<vector<bool>> block;

    // dfs遍历参数用二维，就是从 (0,0) 到 (8,8) 要填的点坐标 (i,j)
    // dfs遍历参数用一维，就是一共要填的81个数，用的时候由一维的81个数转换为对应的二维坐标
    // dfs返回值bool，为true表示能继续dfs，为false表示不能要回溯
    // 很多时候的dfs没返回值，是因为只需沿着遍历点一路走下去，比如二叉树，根本不会发生回溯
    bool dfs (vector<vector<char>>& board, int index) {
        if (index == 81)
            return true;
        // 先把下一个要填的位置提前算出来，避免在回溯里反复地去找
        // 因为next位置是固定的，在这里只需计数一次
        int next = index + 1;
        for (; next < 81; next++)
            if (board[next / 9][next % 9] == '.')
                break;
        // 为当前位置选能填的数据，选好用dfs去填下一个
        int x = index / 9, y = index % 9;
        for (int i = 1; i <= 9; i++)
            if (!row[x][i] && !col[y][i] && !block[x / 3 * 3 + y / 3][i]) {
                row[x][i] = true;
                col[y][i] = true;
                block[x / 3 * 3 + y / 3][i] = true;
                board[x][y] = '0' + i;
                if (dfs (board, next))
                    return true;
                row[x][i] = false;
                col[y][i] = false;
                block[x / 3 * 3 + y / 3][i] = false;
                board[x][y] = '.';
            }
        // 三个方向上1-9的数字都被选过了
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {

        // 回溯前的visited判定
        // 9行9列9方块，每个里面能填的数据是1-9，所以申请为0-9
        row = vector<vector<bool>>(9, vector<bool>(10, false));
        col = vector<vector<bool>>(9, vector<bool>(10, false));
        block = vector<vector<bool>>(9, vector<bool>(10, false));

        // 先把已填上值的数标记上
        // block为什么是 i / 3 * 3 + j / 3 ？
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] != '.') {
                    row[i][board[i][j] - '0'] = true;
                    col[j][board[i][j] - '0'] = true;
                    block[i / 3 * 3 + j / 3][board[i][j] - '0'] = true;
                }

        // 找到第一个需要填的的位置，开始执行dfs进行填写
        int i = 0;
        for (;i < 81; i++)
            if (board[i / 9][i % 9] == '.')
                break;
        dfs(board, i);

        return;
    }
};