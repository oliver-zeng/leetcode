class Solution {
private:
    bool g_debug = false;
    int sz;
    vector<int> tmp;
    vector<vector<int>> res;

    void calcComb(int n, int start) {
        if (g_debug)
            cout << "[" << start << "] enter" << endl;
        // 只起到了提高performance的作用，不是必要的
        // 真正的结束条件是tmp的长度，在start过大时，会进不了循环，走到最下面直接return
        // 而且这个start是要大于n+1，因为n是可以取到的，选n后再进入递归从n+1开始是合理的
        if (start > n + 1) return;
        if (tmp.size() == sz) {
            if (g_debug) {
                cout << "[" << start << "] leaf return : ";
                for (auto elm : tmp)
                    cout << elm << " ";
                cout << endl;
            }
            res.push_back(tmp);
            return;
        }

        // 这里的index + 1实际是n[index]，只不过n是从[1, n]，所以正好等于index + 1
        for (int i = start; i <= n; i++) {
            if (g_debug)
                cout << "[" << start << "] choose " << i << endl;
            tmp.push_back(i);
            calcComb(n, i + 1);
            tmp.pop_back();
        }
        if (g_debug)
            cout << "[" << start << "] return" << endl;
        return;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        // 组合跟排序最大的不同之处在于：
        // 排列每层的兄弟节点，可选的分支个数是相同的，所以只要记录每层选过的数，不要再选到就好了
        // 组合每层兄弟间可选分支个数是不同，所以尽管组合的结果是顺序无关的，
        // 但实际上在求解组合结果的过程中，反而是要按顺序选取的
        // 必须保证，选的数在顺序上都是在前一次选的数后面的
        // 比如[1, 2, 3，4]，如果选了2，下一次选就必须选2后面的数[3, 4]，不能再选[1]
        sz = k;
        res.clear();
        tmp.clear();
        // from [1, n] choose k，先从1开始选
        // 这里就没必要再加一个index来看执行到第几步了
        // 因为反正最后是要得到tmp长度为k时停止的，通过tmp长度就知道何时结束了
        calcComb(n, 1);
        return res;
    }
};
