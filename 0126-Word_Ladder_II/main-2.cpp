// 用递归函数dfs找路径细节（用栈dfs没这问题）：
// dfs相当于是边，每次执行dfs前，往path里加的是to
// for (auto to : g[from]) {
//     path.push_back(vec[to]);
//     dfs(to, ..);
//     path.pop_back();
// }
// 所以在执行第一个dfs前一定要把起点装进path
// path.push_back(vec[begin]);
// dfs(begin, ..)
class Solution {
    bool similar(string &str1, string &str2) {
        int sz = str1.size();
        if (sz != str2.size())
            return false;
        int count = 0;
        for (int i = 0; i < sz; i++) {
            if (str1[i] != str2[i])
                count++;
            if (count > 1)
                return false;
        }
        if (count != 1)
            return false;
        return true;
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        int end = find(wordList.begin(), wordList.end(), endWord) - wordList.begin();
        if (end == wordList.size())
            return res;
        int begin = find(wordList.begin(), wordList.end(), beginWord) - wordList.begin();
        if (begin == wordList.size())
            wordList.push_back(beginWord);
        
        // 邻接矩阵建图
        int sz = wordList.size();
        vector<vector<int>> g(sz, vector<int>());
        for (int i = 0; i < sz; i++)
            for (int j = i+1; j < wordList.size(); j++)
                if (similar(wordList[i], wordList[j])) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
        // bfs是按照层数的先后顺序，存放在队列中的
        // bfs & dfs 都可以用来遍历节点，但找单源最短路只能是bfs
        // 记录bfs路径的方法是，把到当前节点的路径，记录在这个节点里，push进队列
        // 路径中的成员数，可以知道是在第几层
        //（1）第一层：{"ab"}
        //（2）第二层：{"ab","af"}、{"ab","ib"}
        //（3）第三层：{"ab","af","if"}、{"ab","ib","if"}

        // bfs记录层数(vector) or 已访问节点(vector/map)，二选一即可
        // 一般的bfs是访问到该节点一次，就不再访问了
        // 但这题是要找到每层的全部可能，不能每个节点只遍历一次
        // 因此访问过的节点，就不能在当前层立刻标记为访问，需要到新层时再标记
        // 因此只能用集合，先把访问过的节点用集合暂存一下，等到新层时再合并到访问过的集合中去

        // 层序遍历有两种模板
        // 第一种：
        // 把每个pop出节点，下一层的节点入队
        // 当出队节点的层数增加时进入新层，所以必须记录层数
        // 第二种：
        // 把当前队列中节点个数，全部pop处理把下一层节点入队完，再处理下一层的全部节点
        // 每次处理完当前队列节点时进入新层，不必记录层数，只需要记录是否访问过即可

        queue<pair<int, vector<string>>> qe; // cur_node, path
        vector<int> level(sz, 0);
        unordered_set<int> dict;
        vector<string> path({wordList[begin]});
        qe.push(make_pair(begin, path));
        bool find = false;
        // 改成获取每层到vec，然后找到end的时候，仍是不标记level，直接刷新flag
        // 等插入新层的时候，看到flag就直接break
        // 先写出层序遍历的完整输出，再调成后标记每层节点，最后调成提前break
        while (!qe.empty()) {
            int sz = qe.size();
            unordered_set<int> tmp;
            for (int i = 0; i < sz; i++) {
                int from = qe.front().first;
                vector<string> path = qe.front().second;
                qe.pop();
                for (int to : g[from]) {
                    if (dict.count(to)) continue;
                    tmp.insert(to);
                    vector<string> new_path = path;
                    new_path.push_back(wordList[to]);
                    qe.push(make_pair(to, new_path));
                    if (to == end) {
                        find = true;
                        res.push_back(new_path);
                    }
                }
            }
            if (find) break;
            dict.insert(tmp.begin(), tmp.end());
        }
        return res;
    }
};