class Solution {
    bool similar(string &word1, string &word2) {
        if (word1.size() != word2.size())
            return false;
        int diff = 0;
        for (int i = 0; i < word1.size(); i++)
            if (word1[i] != word2[i])
                diff++;
        if (diff == 1)
            return true;
        return false;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 先找到begin & end的位置，vector没有方法find
        // std::find(iter1, iter2, val)在[iter1, iter2)中返回值为val的iter
        // 对于vector val的index为iter - begin()，若没找到iter为end()
        int end = find(wordList.begin(), wordList.end(), endWord) - wordList.begin();
        if (end == wordList.size())
            return 0;
        int begin = find(wordList.begin(), wordList.end(), beginWord) - wordList.begin();
        if (begin == wordList.size())
            // beginWord = "hit" 不在 wordList = ["hot","dot","dog","lot","log","cog"]
            wordList.push_back(beginWord);
        // 邻接表（稀疏图）
        // n个vector里面存放的是index连接点的index
        // 不再是邻接矩阵 n*n 的bool了
        int n = wordList.size();
        vector<vector<int>> g(n, vector<int>());
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                if (similar(wordList[i], wordList[j])) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
        // 用bfs求begin到end的单源最短路径
        queue<pair<int, int>> qe;
        vector<bool> used(n, false);
        qe.push(make_pair(begin, 1));
        used[begin] = true;
        while (!qe.empty()) {
            int index = qe.front().first;
            int level = qe.front().second;
            qe.pop();
            // 在pop时判断，会超时的
            //if (index == end)
            //    return level;
            for (auto i : g[index])
            // 不能写成下面这样，因为g[index]里面存的值才是点的索引
            //for (int i = 0; i < g[index].size(); i++)
                if (used[i] == false) {
                    // 把判断放在push前，而不是pop的时候能快很多
                    if (i == end)
                        return level + 1;
                    qe.push(make_pair(i, level+1));
                    used[i] = true;
                }
        }
        return 0;
    }
};