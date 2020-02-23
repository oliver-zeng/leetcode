class Solution {

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 在wordList [begin, end) 里找到 beginWord & endWord 的位置
        // 没没找到返回的是end，对end - begin == wordList.size()做相应的处理
        int end = find(wordList.begin(), wordList.end(), endWord) - wordList.begin();
        if(end == wordList.size())
            return 0;

        int begin = find(wordList.begin(), wordList.end(), beginWord) - wordList.begin();
        if(begin == wordList.size())
            wordList.push_back(beginWord);

        // 对保护beginWord & endWord 的全部n个节点生成邻接矩阵
        int n = wordList.size();
        vector<vector<bool>> g(n, vector<bool>(n, false));
        // 遍历[0, sz)所有两两不同点的方法有两个
        // i到[0, sz)，j到[0, i) 或 (i, sz) 效果都是一样的
        for(int i = 0 ; i < wordList.size() ; i ++)
            //for(int j = i+1 ; j < wordList.size() ; j ++)
            for(int j = 0 ; j < i ; j ++)
                g[i][j] = g[j][i] = similar(wordList[i], wordList[j]);

        // bfs
        queue<pair<int, int>> q;
        vector<bool> visited = vector<bool>(n, false);
        visited[begin] = true;
        // 从Explanation里看beginWord自己也算了一个数，所以层数需要从1开始计数
        q.push(make_pair(begin, 1));
        while (!q.empty()) {
            int pos = q.front().first;
            int level = q.front().second;
            q.pop();
            for (int i = 0; i < n; i++) {
                if (!visited[i] && g[pos][i]) {
                    if (i == end)
                        return level + 1;
                    visited[i] = true;
                    q.push(make_pair(i, level + 1));
                }
            }
        }

        return 0;
    }

private:
    // 判断两点是否有边，有边的标准是：
    // 两点所代表的字符串，只差一个字母
    bool similar(const string& word1, const string& word2){

        assert(word1 != "" && word1.size() == word2.size() && word1 != word2);

        int diff = 0;
        for(int i = 0 ; i < word1.size() ; i ++)
            if(word1[i] != word2[i]){
                diff ++;
                if(diff > 1)
                    return false;
            }
        return true;
    }
};
