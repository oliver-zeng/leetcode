#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    bool g_debug = false;
    int debug_count = 0;
    int sz;
    vector<vector<string>> res;
    vector<bool> col, left_dia, right_dia;
    vector<string> tmp;
    string s;
    bool inArea(int x, int y) {
        if (g_debug)
            cout << "check used["<< x << "][" << y <<"] ";
        if ((x < 0) || (x >= sz) || (y < 0) || (y >= sz)) {
            if (g_debug)
                cout << "false" << endl;
            return false;
        } else {
            if (g_debug)
                cout << "true" << endl;
            return true;
        }
    }
    // 仍是组合，只要按照顺序，在接下来后面的位置选即可
    // n皇后，在n*n矩阵中，每行只能放一个，在每行选好后
    // 会影响到后面的三个方向：左斜、右斜，竖直
    // 三个方向的两个坐标，所以是d[3][2]
    // 特别注意方向坐标一定要写对，最好试一下，否则错了查起来很难debug
    // 下面这种标记方法，之间会打架，以 5 * 5举例：
    // 在第一行选(0, 0)，会标记第一纵列
    // ["Q....",
    // "Q....",
    // "Q....",
    // "Q....",
    // "Q...."],
    // 在第二行选(1, 3)，会标记右对角线
    // [".....Q",
    // "....Q.",
    // "...Q..",
    // ".Q...",
    // "Q...."],
    // 此时可以看到，在两次标记上发生了重叠(4, 0)
    // 在第二行不选(1,3)的回溯操作时，会把第一行标记的(4, 0)给清掉
    //int d[3][2] = {{1, -1}, {1, 1}, {1, 0}};
    //vector<vector<bool>> used;
    //void setUsed(int x, int y, bool use) {
        //int newx, newy;
        ////used[x][y] = use;
        //for (int i = 0; i < 3; i++) {
            //newx = x + d[i][0];
            //newy = y + d[i][1];
            //while(inArea(newx, newy)) {
                //if (g_debug)
                    //if (use)
                        //cout << "set used[" << newx << "][" << newy << "] true" <<  endl;
                    //else
                        //cout << "set used[" << newx << "][" << newy << "] false" <<  endl;
                //used[newx][newy] = use;
                //newx = newx + d[i][0];
                //newy = newy + d[i][1];
            //}
        //}
        //return;
    //}
    void setUsed(int x, int y, bool use) {
       col[y] = use;
       left_dia[x - y + sz - 1] = use;
       right_dia[x + y] = use;
    }
    void setRow(int x) {
        if (x == sz) {
            if (g_debug) cout << "solution " << debug_count++ << endl;
            //if (debug_count == 2) g_debug = false;
            res.push_back(tmp);
            return;
        }
        for (int y = 0; y < sz; y++) {
            //if (g_debug) {
                //cout << "x " << x << " y " << y << endl;
                //if (used[x][y])
                    //cout << "used[x][y] true" << endl;
                //else
                    //cout << "used[x][y] false" << endl;
            //}
            if (!col[y] && !left_dia[x - y + sz -1] && !right_dia[x+y]) {
                setUsed(x, y, true);
                s = string(sz, '.');
                s[y] = 'Q';
                tmp.push_back(s);
                if (g_debug)
                    cout << s << endl;

                setRow(x + 1);

                tmp.pop_back();
                setUsed(x, y, false);
            }
        }
        return;
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        sz = n;
        //used = vector<vector<bool>>(n, vector<bool>(n, false));
        // 循环只能遍历，如果要退回到上一层这种操作，就只能用回溯
        // 只有回溯才能在i行不行时，回退到i-1行重新选位置
        /*for (int i = 0; i < n; i++) {
            if (setRow(i)) continue;
        }*/
        col = vector<bool>(n, false);
        left_dia = vector<bool>(2 * n - 1, false);
        right_dia = vector<bool>(2 * n - 1, false);
        setRow(0);
        return res;
    }
};

int main() {
    vector<vector<string>> res = Solution().solveNQueens(5);
    for (int i = 0; i < res.size(); i++) {
        cout << "solution " << i << endl;
        for (int j = 0; j < res[i].size(); j ++)
            cout << res[i][j] << endl;
        cout << endl;
    }
    return 0;
}
