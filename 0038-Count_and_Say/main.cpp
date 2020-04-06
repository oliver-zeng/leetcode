class Solution {
    string dfs(int n) {
        if (n == 1)
            return "1";
        string str = dfs(n - 1);
        string res;
        int count = 1;
        char c = str[0];
        for (int i = 1; i < str.size(); i++) {
            if (str[i] == str[i-1]) {
                count++;
                continue;
            }
            res += to_string(count) + c;
            count = 1;
            c = str[i];
        }
        // 最后要加一步，防止在循环结束时，
        // 最后一次的str[i] == str[i-1]没有统计上
        res += to_string(count) + c;
        return res;
    }
public:
    string countAndSay(int n) {
        // dfs
        // 自顶向下，不需要知道执行到第几层了，最后到了base case一定会向上返回
        // 自底向上，需要有个step，以便知道是否走到了顶层了
        // 所以同样是递归，用自顶向下会省参数
        return dfs(n);
    }
};