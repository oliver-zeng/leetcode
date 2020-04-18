class Solution {
    class UnionFind {
        vector<int> parent;
        vector<int> rank;
        int count;
    public:
        UnionFind (int n) {
            for (int i = 0; i < n; i++)
                parent.push_back(i);
            rank = vector<int>(n, 1);
            count = n;
        }
        // 若p不是根节点，直接把p的父链上所有点都指向根，之后返回根节点
        int find (int p) {
            if (parent[p] == p)
                return p;
            parent[p] = find(parent[p]);
            return parent[p];
        }
        void link (int p, int q) {
            int proot = find(p);
            int qroot = find(q);
            if (proot == qroot)
                return;
            // 把rank低的根节点，指向rank高的，不会影响到rank高的树高
            if (rank[proot] < rank[qroot])
                parent[proot] = qroot;
            else if (rank[qroot] < rank[proot])
                parent[qroot] = proot;
            else { // rank相同时，被插入根节点的rank会被垫高
                parent[proot] = qroot;
                rank[qroot]++;
            }
            // 连通分量个数减少
            count--;
        }
        int getCount () {
            return count;
        }
    };
public:
    int numIslands(vector<vector<char>>& grid) {
        // 获取二维vector行列sop
        int row = grid.size();
        if (row == 0) return 0;
        int col = grid[0].size();
        if (col == 0) return 0;
        
        // union find 只要能在遍历时都连通就行，所以只需要右跟下两个方向
        int d[2][2] = {{1, 0}, {0, -1}};
        // 把所有的'0'都连到parent[row * col]
        UnionFind uf(row * col + 1);
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (grid[i][j] == '0')
                    uf.link(i * col + j, row * col);
                else {
                    for (int k = 0; k < 2; k++) {
                        int x = i + d[k][0];
                        int y = j + d[k][1];
                        if (x < row && y >= 0 && grid[x][y] == '1')
                            uf.link(i * col + j, x * col + y);
                    }
                }
        return uf.getCount() - 1;
    }
};