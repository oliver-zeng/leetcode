// tarjan求有向图的强连通分量（局部成环）
// dfs求节点to能到达的节点最低level，并把每个点的dfs值记录下来以提高dfs效率
// 如果成环，环上所有点都将为环上的level最低的值
// 若没有环，从当前深度再往下dfs，肯定深度都是比它大的
// 所以最小深度仍将维持原值，就是没有环
// 但这里有一个例外，就是起始点，因为不管有没有环它都是最低的起始level值
// 处理办法就是，排除起始点，比较其他节点后，用当前节点与它的父节点做边
// 这样就可以完美避开对起始点level的判断，同时还能处理到from是起始点的情况了
class Solution {
    int dfs(vector<vector<int>> &g, int from, int parent, int level, vector<int> &low, vector<vector<int>> &res) {
        low[from] = level;
        for (auto to : g[from]) {
            // 避免倒着走回去，无向图任意边成环的情形
            if (to == parent) continue;
            if (low[to] != -1) {
                low[from] = min(low[from], low[to]);
                continue;
            }
            low[from] = min(low[from], dfs(g, to, from, level + 1, low, res));
        }
        // 根据to更新from的low，判断的边是(par, from)
        // 把没有环的边加入返回值即可
        if (low[from] == level && from != 0)
            res.push_back({parent, from});
        return low[from];
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> g(n, vector<int>());
        for (auto e : connections) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<vector<int>> res;
        vector<int> low(n, -1);
        // 这里只需要从0开始就可以了，不需要对所有的点进行处理
        // 因为这个是无向图，只要是连通的
        // 从哪个点开始都可以通过dfs一次遍历到所有的点
        dfs(g, 0, -1, 0, low, res);
        return res;
    }
};