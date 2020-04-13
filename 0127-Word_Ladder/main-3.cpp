class Solution {
private:
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
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int end = find(wordList.begin(), wordList.end(), endWord) - wordList.begin();
        if (end == wordList.end() - wordList.begin())
            return 0;
        int begin = find(wordList.begin(), wordList.end(), beginWord) - wordList.begin();
        if (begin == wordList.end() - wordList.begin())
            wordList.push_back(beginWord);

        // 邻接表建图
        int sz = wordList.size();
        vector<vector<int>> g(sz, vector<int>());
        for (int i = 0; i < sz - 1; i++)
            for (int j = i+1; j < sz; j++)
                if (similar(wordList[i], wordList[j])) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
        // 不用 pair 把 index 与 level 绑定在一起，单用一个 level[] 存放会快很多
        // PS：如果 level 从 0 开始，那 level[] 初始值应该赋值为 -1 代表没算过
        // bfs
        // 从源点开始，把每个相邻点入队，每个点只能入队一次
        // 用bool viisted或int level判断重复
        // 用visited，如果只是求单源最短路径，后面不会再用到
        // 就可以把level放进pair，因为记录下来的level会随queue pop全都丢掉的
        // 用level就不能放进pair，且初值要都设为0，源点level从1开始，这样不为0的就是重复的
        // 所以还是最推荐，不与顶点绑定，单独外置建立一个level
        // 直至找到目标点为止，计算层高
        queue<int> q;
        vector<int> level(sz, 0);
        level[begin] = 1;
        q.push(begin);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto elm : g[cur]) {
                if (elm == end)
                    return level[cur] + 1;
                if (!level[elm]) {
                    level[elm] = level[cur] + 1;
                    q.push(elm);
                }
            }
        }
        return 0;
    }
};
