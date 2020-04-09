#define BACKTRACE
class Solution {
#ifdef BACKTRACE
    // 回溯，tmp是引用，这样选择的资源才是公用的，需要在执行dfs前后进行一进一出
    void dfs(string &tmp, vector<string> &res, int left, int right) {
#else
    // 直接把每次的选择作为新的参数赋值给状态，因为参数的传递不是引用
    // 所以在执行dfs调用前后实质都未曾改变过，所以自然也就不需要回退了
    void dfs(string tmp, vector<string> &res, int left, int right) {
#endif
        if (left == 0 && right == 0) {
            res.push_back(tmp);
            return;
        }
#ifdef BACKTRACE
        // 回溯法，在每个状态做所有可能的选择
        // 因为选择所用的资源是共有的，所以在每次选完执行dfs后
        // 还要再把所做选择所用到的资源退回来供接下来的选择使用
        if (left > 0) {
            tmp += '(';
            left--;
            dfs(tmp, res, left, right);
            left++;
            tmp.pop_back();
        }
        if (right > 0 && left < right) {
            tmp += ')';
            right--;
            dfs(tmp, res, left, right);
            right++;
            tmp.pop_back();
        }
#else
        // 把每次选择用到的资源，作为新的参数重新执行dfs就不需要进行显示的“回溯”了
        if (left > 0)
            dfs(tmp+"(", res, left-1, right);
        if (right > 0 && left < right)
            dfs(tmp+")", res, left, right-1);
#endif
    }
    // dfs 也可以写成自底向上的
    // 结束条件变为 if (left == n && right == n)
    // 选择状态变为 if (left < n) dfs(tmp+"(", res, n, left+1, right);
    //            if (right < n && left > right) dfs(tmp+")", res, n, left, right-1);
    // 但是这样做，定义的时候就会多一个最终结束参数n，调用时写成 dfs("", res, n, 0, 0)
    // 自顶向下最终结束状态0，相当于是已知的，写起来就会少用一个递归结束状态的参数
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
#ifdef BACKTRACE 
        string tmp = "";
        dfs(tmp, res, n, n);
#else
        dfs("", res, n, n);
#endif
        return res;
    }
};