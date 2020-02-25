class Solution {
public:
   int numberOfBoomerangs(vector<vector<int>>& points) {
        int sz = points.size();
        int res = 0;
        // 因为是任一找两点，而不是一前一后的所有组合
        // 所以i的选择就不是[0, sz - 1)了
        // for (int i = 0; i < sz - 1; i++) {
        for (int i = 0; i < sz; i++) {
            unordered_map<int, int> record; // {distance, points_count}
            // 这个是任一点，与其他所有点去比，所以不能舍掉前面的点
            // 如 [[0,0],[1,0],[2,0]] 答案是 [1,0]与[0,0]&[2,0]构成等边
            // 在[1, 0]舍掉[0, 0]就错了
            //for (int j = i + 1; j < sz; j++) {
            for (int j = 0; j < sz; j++) {
                if (i == j) continue;
                int x = points[i][0] - points[j][0];
                int y = points[i][1] - points[j][1];
                // 计算距离时不进行开根运算, 以保证精度
                int distance = x*x + y*y;
                record[distance]++;
            }
            // elm最小值是1，选2个数的排列是1*0不影响res结果
            // 所以不用每次判断是1不能算进去了
            for (auto elm : record)
                res += elm.second * (elm.second - 1);
        }
        return res;
    }
};