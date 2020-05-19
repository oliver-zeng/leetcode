class Solution {
    // 这里的决定是否会超时的灵魂函数similar
    // 1. 参数必须是引用
    // 2. 在得知diff > 1时就不要再比较了，必须要立刻return false
    // 3. str.size()一定要少用
#ifdef TIME_OUT
    bool similar(string s1, string s2) {
#else
    bool similar(string &s1, string &s2) {
#endif
#if TIME_OUT
        if (s1.size() != s2.size())
            return false;
#else
        int sz = s1.size();
        if (sz != s2.size())
            return false;
#endif
        int diff = 0;
#ifdef TIME_OUT
        for (int i = 0; i < s1.size(); i++)
            if (s1[i] != s2[i]) diff++;
        if (diff == 1)
            return true;
#else
        for (int i = 0; i < sz; i++) {
            if (s1[i] != s2[i])
                diff++;
            if (diff > 1) // diff > 1 就直接return，不用再算了
                return false;
        }
        if (diff)
            return true;
#endif
        return false;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int end = find(wordList.begin(), wordList.end(), endWord) - wordList.begin();
        if (end == wordList.size())
            return 0;
        int begin = find(wordList.begin(), wordList.end(), beginWord) - wordList.begin();
        if (begin == wordList.size())
            wordList.push_back(beginWord);

        vector<vector<int>> g(wordList.size(), vector<int>());
        for (int i = 0; i < g.size() - 1; i++)
            for (int j = i+1; j < g.size(); j++)
                if (similar(wordList[i], wordList[j])) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }

        // 按照层数作为访问，第一层要从0开始
        queue<int> qe;
        vector<int> level(wordList.size(), 0);
        level[begin] = 1;
        qe.push(begin);
        while (!qe.empty()) {
            int from = qe.front();
            qe.pop();
            for (auto to : g[from]) {
                if (level[to]) continue;
                if (to == end) return level[from] + 1;
                qe.push(to);
                level[to] = level[from] + 1;
            }
        }
        return 0;
    }
};