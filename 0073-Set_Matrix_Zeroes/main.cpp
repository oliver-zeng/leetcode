class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (row == 0) return;
        int col = matrix[0].size();
        if (col == 0) return;
        
        vector<bool> urow(row, false);
        vector<bool> ucol(col, false);
        
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (matrix[i][j] == 0) {
                    urow[i] = true;
                    ucol[j] = true;
                }
        
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if ((urow[i] || ucol[j]))
                    matrix[i][j] = 0;
        
        return;
    }
};