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
        // 用邻接表
        vector<vector<int>> g(wordList.size(), vector<int>());
        for (int i = 0; i < wordList.size() - 1; i++)
            for (int j = i + 1; j < wordList.size(); j++)
                if (similar(wordList[i], wordList[j])) {
                    g[i].push_back(j);
                    g[j].push_back(i); // 因为i永远小于j，所以j < i的边必须这时候连上
                }

        // 广度优先，求邻接表单元最短路径
        // 是否进入过queue中需要额外通过visited或level记录
        queue<int> q;
        // 这里level不能用pair跟节点绑定，而是要单独存放
        // 因为queue中的在pair里记录的level，最终都会pop出去
        // 后面回溯时，除了两点是否连接，还会用到层序关系level
        vector<int> level(wordList.size(), 0);
        // 靠level判断是否访问过，所以begin level要从1开始
        level[begin] = 1;
        q.push(begin);
        while (!q.empty()) {
            int pos = q.front();
            q.pop();
            for (auto elm : g[pos]) {
                if (!level[elm]) {
                    q.push(elm);
                    level[elm] = level[pos] + 1;
                }
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
    void traverse(int cur, int end, vector<vector<int>> &g, vector<int> &level, vector<string> &wordList) {
        if (level[cur] == level[end]) {
            // 找到了，同一深度的不同点，也是不对的
            if (wordList[cur] == wordList[end])
                res.push_back(tmp);
            return;
        }

        for (auto elm : g[cur]) {
            if (level[elm] == level[cur] + 1) {
                tmp.push_back(wordList[elm]);
                traverse(elm, end, g, level, wordList);
                tmp.pop_back();
            }
        }
    }
};
