class Solution {
private:
    int res = 0;
    void dfs(int n, int index, vector<bool> &col, vector<bool> &left_dia, vector<bool> &right_dia) {
        if (index == n) {
            res++;
            return;
        }
        // 在第index行的列上选一个位置，即(index, i)    
        for (int i = 0; i < n; i++) {
            if (!col[i] && !left_dia[index - i + n - 1] && !right_dia[index + i]) {
                col[i] = true;
                left_dia[index - i + n - 1] = true;
                right_dia[index + i] = true;
                dfs(n, index + 1, col, left_dia, right_dia);
                col[i] = false;
                left_dia[index - i + n - 1] = false;
                right_dia[index + i] = false;
            }
        }
    }
public:
    int totalNQueens(int n) {
        vector<bool> col(n, false);
        vector<bool>  left_dia(2 * n - 1, false);
        vector<bool> right_dia(2 * n - 1, false);
        dfs(n, 0, col, left_dia, right_dia);

        return res;
    }
};