class Solution {
public:
    int numSquares(int n) {

        // 用pair结构同时记录顶点，与此点距源点的距离（即广度优先遍历的层数）
        queue<pair<int, int>> q;
        q.push(make_pair(n, 0));

        // 为每个点做标记，确保每个点只进入queue一次
        // 避免图上同一个顶点，做为相邻顶点多次被推入队列，造成大量重复计算
        //vector<bool> visited = vector<bool>(n+1, false);
        vector<bool> visited(n + 1, false);
        visited[n] = true;

        // bfs
        while (!q.empty()) {
            int num = q.front().first;
            int level = q.front().second;
            q.pop();
            // 每次出队的点，把没入过队的相邻顶点都推入队列
            // 这些由出队顶点推入的点，是此出队顶点下一层上面的点
            for (int i = 0; i * i <= num; i++) {
                int tmp = num - i*i;
                if (!visited[tmp]) {
                    // 当找到目标点时，直接返回目标点的层数即可
                    if (tmp == 0)
                        return level + 1;
                    visited[tmp] = true;
                    q.push(make_pair(tmp, level + 1));
                }
            }
        }

        // error:control reaches end of non-void function[-Werror=return-type]
        // 在函数的最后一定要返回对应的数据类型，哪怕是永远也用不上
        // return -1;
        // 但因为返回的是无意义的值，可以写成抛出一个异常来代替dummy value
        throw invalid_argument("No Solution.");
    }
};
