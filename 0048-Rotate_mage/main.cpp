#define USE_ROTATE
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 顺时针90度旋转规律：
        // 每一个需要旋转的点，产生的环，固定为4次
        // 如：1->3->9->7->1
        // 坐标为(i, j) -> (j, col-1-i)
        // 需要旋转的点由外向内，n*n矩阵只需要旋转前[0, n/2]行的点
        // 每一行要选择的点依次为，第一行[0, col-1)，第二行[1, col-2)，...
        int row = matrix.size();
        if (row == 0) return;
        int col = matrix[0].size();
        if (col == 0) return;

        int level = row/2;
        for (int i = 0; i < level; i++)
            // 这里不能是<=，以第一行为例，实际范围不是从[0, col-1]，
            // 因为第[col-1]个位置是[0]换过去的位置，不能旋转，所以是[0, col-1)
            //for (int j = i; j <= col-1-i; j++) {
            for (int j = i; j < col-1-i; j++) {
                // rotate 要用两套位置 & 值来实现，在进入循环前，先记录cur
                // 在循环中，等记录完next后，再把next替换为cur，最后将cur更新为next
                // 先做一次以后，循环执行，用于判断回到原点时使用
                int curi = i, curj = j;
                int cur = matrix[curi][curj];
#ifdef USE_ROTATE
                // do while 的使用场景是找环
                // 以起始位置的条件作为跳出条件，先do一次，离开起始位置
                // 等环回到起始位置时，再做就是重复的了，正好结束执行
                do {
                    int nexti = curj, nextj = col-1-curi;
                    int tmp = matrix[nexti][nextj];
                    matrix[nexti][nextj] = cur;
                    curi = nexti;
                    curj = nextj;
                    cur = tmp;
                } while (curi != i || curj != j);
#else

                int count = 4;
                while (count--) {
                    int nexti = curj, nextj = col-1-curi;
                    int tmp = matrix[nexti][nextj];
                    matrix[nexti][nextj] = cur;
                    curi = nexti;
                    curj = nextj;
                    cur = tmp;
                }
#endif
            }
        return;
    }
};