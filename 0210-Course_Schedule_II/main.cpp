// 有向无环图(Directed Acyclic Graph简称DAG)
// 拓扑排序是将DAG中所有顶点排成一个线性序列
// 使得图中任意一条有向边(from,to)，在序列中满足from出现在to前
class Solution {
    // 判断是否有环
    bool loop = false;
    void dfs(int from, int numCourses, const vector<vector<int>> &g, vector<int> &lock, vector<int> &res) {
        lock[from] = 1;
        for (auto to : g[from]) {
            if (lock[to] == 2) continue;
            if (lock[to] == 1) {
                loop = true;
                return;
            }
            dfs(to, numCourses, g, lock, res);
        }
        lock[from] = 2;
        res.push_back(from);
        return;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses, vector<int>());
        for (auto elm : prerequisites)
            g[elm[1]].push_back(elm[0]);
        // 因为在图上起点不确定，要尝试每个点作为起点
        // 所以这里lock不再用bool，要改为int：
        // 除了0没搜索过，1在dfs里搜索中可检测环外
        // 还有第三种状态2，当dfs置1结束后不再清0，要改为2表示已搜索过
        vector<int> lock(numCourses, 0);
        vector<int> res;
        for (int i = 0; i < numCourses; i++) {
            if (loop) return {};
            if (lock[i] == 2)
                continue;
            dfs(i, numCourses, g, lock, res);
        }
        // 最后为2插入res的是先决条件
        // 而最早为2插入res的是要基于后面插入的先决条件，在最后完成的
        reverse(res.begin(), res.end());
        return res;
    }
};