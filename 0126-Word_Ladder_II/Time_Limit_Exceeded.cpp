// 邻接表 适合记录 点上边少的稀疏图
// 邻接矩阵 适合记录 点上边多的稠密图
// 这题测试用例点很多，但每个点上能连边很少，每个点上similar为true的不多，所以要用邻接表
class Solution {
private:
    // 两顶点的连接关系
    bool similar(string &word1, string &word2) {
        int sz = word1.size();
        if (sz != word2.size())
            return false;
        int diff = 0;
        for (int i = 0; i < sz; i++) {
            if (word1[i] != word2[i])
                diff++;
            if (diff > 1)
                return false;
        }
        if (diff)
            return true;
        else
            return false;
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // 处理顶点：起点&终点
        int end = find(wordList.begin(), wordList.end(), endWord) - wordList.begin();
        if (end == wordList.end() - wordList.begin())
            return {};
        int begin = find(wordList.begin(), wordList.end(), beginWord) - wordList.begin();
        if (begin == wordList.end() - wordList.begin())
            // 此时begin已经在之前的end()上，就不需要再赋值了
            wordList.push_back(beginWord);

        // 建图，按“连接”条件，判断每个点是否连接
        // 用邻接矩阵
        int n = wordList.size();
        vector<vector<bool>> g(n, vector<bool>(n, false));
        // 遍历[0, sz)所有两两不同点的方法有两个
        // i到[0, sz)，j到[0, i) 或 (i, sz) 效果都是一样的
        for(int i = 0 ; i < n - 1; i ++)
            for(int j = i+1 ; j < n; j ++)
                g[i][j] = g[j][i] = similar(wordList[i], wordList[j]);

        // 广度优先，求邻接矩阵单元最短路径
        queue<int> q;
        vector<int> level(n, 0);
        level[begin] = 1;
        q.push(begin);
        while (!q.empty()) {
            int pos = q.front();
            q.pop();
            for (int i = 0; i < n; i++)
                if (!level[i] && g[pos][i]) {
                    level[i] = level[pos] + 1;
                    q.push(i);
                }
        }

        // 回溯
        // begin是一定在的，不能通过回溯时进进出出得到，所以首先放进去
        tmp.push_back(wordList[begin]);
        traverse (begin, end, g, level, wordList);
        return res;
    }
private:
    vector<string> tmp;
    vector<vector<string>> res;
    void traverse(int cur, int end, vector<vector<bool>> &g, vector<int> &level, vector<string> &wordList) {
        if (level[cur] == level[end]) {
            // 找到了，同一深度的不同点，也是不对的
            if (wordList[cur] == wordList[end])
                res.push_back(tmp);
            return;
        }

        for (int i = 0; i < wordList.size(); i++) {
            if (g[cur][i] && level[i] == level[cur] + 1) {
                tmp.push_back(wordList[i]);
                traverse(i, end, g, level, wordList);
                tmp.pop_back();
            }
        }
    }
};
