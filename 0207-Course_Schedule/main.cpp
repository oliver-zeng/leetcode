class Solution {
private:
    // 有环返回true，没环返回false
    bool dfsCyc(int i, vector<vector<int>> &g, vector<bool> &visited, vector<bool> &hasCycle) {
        // 上锁开锁，都要在递归里进行
        // 在一进 & 出递归的时候使用
        // 标记访问也是一样
        visited[i] = true;
        hasCycle[i] = true;
        for (auto next : g[i])
            // 如果都没有访问过，那肯定没有上过锁了
            if (!visited[next]) {
                //visited[next] = true;
                //hasCycle[next] = true;
                if (dfsCyc(next, g, visited, hasCycle))
                    return true;
            } else if (hasCycle[next])
                return true;
        hasCycle[i] = false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // 没有课，肯定可以修完
        if (prerequisites.size() == 0)
            return true;

        vector<vector<int>> g(numCourses, vector<int>());
        for (auto requisit : prerequisites)
            g[requisit[1]].push_back(requisit[0]);

        vector<bool> visited(numCourses, false);
        vector<bool> hasCycle(numCourses, false);
        for (int i = 0; i < numCourses; i++)
            if (!visited[i]) {
                //visited[i] = true;
                //hasCycle[i] = true;
                if (dfsCyc(i, g, visited, hasCycle))
                    return false;
                //hasCycle[i] = false;
            }

        return true;
    }
};