class Solution {
    // bfs特点，每个点只会访问一次，当访问到这个点时是该点距距源点（无论单源还是多源）最短的路径
    // 「Tree 的 BFS」是「单源 BFS」，「图 的 BFS」依题意有可能是「多源 BFS」
    // Tree 只有 1 个 root，而图可以有多个源点，所以首先需要把多个源点都入队；
    // Tree 是有向的因此不需要标识是否访问过，而对于无向图来说，必须得标志是否访问过
    // bfs特殊在可以通过记录level/distance来作为访问，dfs就只能用used来标志访问了
    // 注意这个点是否已访问，在决定调用dfs/bfs前就判断，而不能在进入dfs/bfs前，否则会超时
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (row == 0) return {};
        int col = matrix[0].size();
        if (col == 0) return {};
        // 不需要额外建一个二维数组res来存储答案，直接将答案更新在原数组matrix中
        // 答案中点0距离最近0点的距离仍为0，点1距离最近0点距离是要求的，先初始化为-1，标明为还没算过的点1
        // 将所有的0点，即已经算出来的点都入队
        queue<pair<int, int>> qe;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (matrix[i][j] == 0)
                    qe.push(make_pair(i,j ));
                else // 把点1的答案初始化为-1，表示还没算过
                    matrix[i][j] = -1;
        // 这些入队的点，是已经算出来的点，里面存放的是距离最近0点的距离
        // 如果找到临近上下左右四方向上值为-1，还没算过的点，就更新这个点的最近距离
        // 然后把这个算完的点重新入队，再去已这个点按上下左右四方向去更新其他没算过的值为-1的点
        int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!qe.empty()) {
            int x = qe.front().first;
            int y = qe.front().second;
            qe.pop();
            for (int i = 0; i < 4; i++) {
                int newx = x + d[i][0];
                int newy = y + d[i][1];
                if (newx >= 0 && newx < row && newy >= 0 && newy < col && matrix[newx][newy] == -1) {
                    matrix[newx][newy] = matrix[x][y] + 1;
                    qe.push(make_pair(newx, newy));
                }
            }
        }
        return matrix;
    }
};