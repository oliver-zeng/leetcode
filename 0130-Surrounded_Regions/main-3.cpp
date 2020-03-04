class Solution {
private:
    class UnionFind {
        public:
             // parent[i]表示第i个元素所指向的父节点
            int *parent;
        //private:
            // rank[i]表示以i为根的集合当前的树高
            // 由于只在根节点记录了当前的树高，当引入路径压缩时，将无法维护rank的树高
            // 因为只记录了根节点的树高，而没有记录非根节点的树高
            // 当同rank的两点合并时，层数低的点通过find路径压缩后树的高度会更小
            // 但哪个层数低不得为之，所以也就无法实现在压缩后把树低的插入树高
            // 极端例子：一个是根，一个是叶子，find完肯定是叶子的低，要把低的插高的
            // 所以在union时引入rank，与在find使用路径压缩，两种优化方式，只能二选其一
            int *rank;
        UnionFind (int sz) {
            parent = new int[sz];
            rank = new int[sz];
            // 构造时，先假设每个点的根节点就是他们自己
            // 此时，以每个点为根节点的层数都为1
            for (int i = 0; i < sz; i++) {
                parent[i] = i;
                rank[i] = 1;
            }
        }
        ~UnionFind () {
            delete[] parent;
            delete[] rank;
        }
        // 并查集解决连通问题，主要操作有：
        // 查找：找到点p的根节点（根节点是父节点指向自己的节点）
        // 合并：将两个点p和q所属的集合合并（把rank低的根节点的父节点改为rank高的根节点）
        // 判断是否相连：两个点具有相同父节点
        // 通过 赋初值构造 -> 遍历所有节点把相连节点合并 -> 通过是否相连求连通性
        int find(int p) {
            if (p != parent[p]) {
                // 路径压缩，把p的父亲直接指到根节点
                // 通过递归实现，可以把p到root路径上的所有点的父节点指向根节点
                parent[p] = find(parent[p]);
            }
            // 返回根节点 parent[p]
            return parent[p];
        }
        void unionElm(int p, int q) {
            int proot = find(p);
            int qroot = find(q);
            if (proot == qroot)
                return;
            // 不等高时，低的插入高的，高的树高不变
            if (rank[proot] > rank[qroot]) {
                parent[qroot] = proot;
            } else if (rank[proot] < rank[qroot]) {
                parent[proot] = qroot;
            } else { // rank[proot] == rank[qroot]
                // 把proot父亲指向qroot，因为原本二者等高，所有qroot树高加1
                parent[proot] = qroot;
                rank[qroot]++;
            }
        }
        bool isConnected(int p, int q) {
            return find(p) == find(q);
        }
    };
    // for this case
    int row, col, dummy;
    int direct[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool inArea(int i, int j) {
        return i >= 0 && i < row && j >= 0 && j < col;
    }
    void unionElm(int p, int q, UnionFind &uf) {
            int proot = uf.find(p);
            int qroot = uf.find(q);
            if (proot == qroot)
                return;
            if (proot == dummy) {
                uf.parent[qroot] = proot;
            } else if (qroot == dummy) {
                uf.parent[proot] = qroot;
            } else {
                uf.parent[qroot] = proot;
            }
        }
public:
    void solve(vector<vector<char>>& board) {
        // 获取二维vector行列的标准写法
        row = board.size();
        if (row == 0) return;
        col = board[0].size();
        if (col == 0) return;

        // 把四条边上为'O'的点，在并查集中标记为dummy = row * col
        // 因为正常点范围是[0, row * col)
        // 必须在并查集中多一个点来作为父节点dummy
        // 因为find的结束条件是p = parent[p]
        UnionFind uf = UnionFind(row * col + 1);
        dummy = row * col;
        // 在二维[i][j]对应到并查集里点的个数是parent[i * col + j]
        for (int i = 0; i < row; i++) {
            if (board[i][0] == 'O')
                uf.parent[i * col] = dummy;
            if (board[i][col - 1] == 'O')
                uf.parent[i * col + col - 1] = dummy;
        }
        for (int j = 0; j < col; j++) {
            if (board[0][j] == 'O')
                uf.parent[j] = dummy;
            if (board[row - 1][j] == 'O')
                uf.parent[(row - 1) * col + j] = dummy;
        }
        // 用并查集遍历全部点
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O') {
                    for (int d = 0; d < 4; d++) {
                        int x = i + direct[d][0];
                        int y = j + direct[d][1];
                        if (inArea(x, y))
                            // 在并查集里union操作时，无法确保合并后root的值
                            // 这题必须保证，跟边上的'O'合并后，还是边上'O'的值
                            // 所以要定制化一下，并查集的union操作
                            if (board[x][y] == 'O')
                            unionElm(x * col + y, i * col + j, uf);
                    }
                }
                    
            }
        // 只改变不与边上'O'连通的'O'点即可
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O' && uf.find(i * col + j) != dummy)
                    board[i][j] = 'X';
            }
         return;  
    }
};