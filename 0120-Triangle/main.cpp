class Solution {
private:
    vector<vector<int>> memo;
    int calcMin(vector<vector<int>>& triangle, int row, int col) {
        // 因为是-1操作，所以直接用[0, row-1]中越界值0或row-1作为递归结束条件即可
        // 又因为会越界的是下边界，所以递归结束条件为row == 0和col == 0
        // 并且这题对每行的首位元素的值，跟其他元素的递归表达式不一致，也需要单独讨论
        if (row == 0) return triangle[0][0];
        if (col == 0) return triangle[row][0] + calcMin(triangle, row - 1, 0);
        if (col == row) return triangle[row][col] + calcMin(triangle, row-1, col-1); 
        if (memo[row][col] == -1)
        	memo[row][col] = min(calcMin(triangle, row - 1, col - 1), calcMin(triangle, row - 1, col)) + triangle[row][col];
        return memo[row][col];
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        memo = vector<vector<int>>(row, vector<int>(row, -1));
        memo[0][0] = triangle[0][0];
        int res = INT_MAX;
        for (int col = 0; col < row; col++)
            res = min(res, calcMin(triangle, row-1, col));
        return res;
    }
};
