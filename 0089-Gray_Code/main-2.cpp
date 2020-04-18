class Solution {
public:
    // n每增加一位，是在高位多了一倍的编码
    // n = 1
    // 0
    // 1
    // n = 2
    // 00
    // 01
    // 10
    // 11
    // gray code 是每一个编码间只改变一位
    // 原有编码顺序本身是只差1位的，无论正序还是倒序均可
    // 加高1位间也是满足的，只需要把新增高位与原有编码衔接处只差1位即可
    // 所以新增的编码，要在原有编码顺序倒序，加高位1得到
    // 00
    // 01
    // 01 + 10
    // 00 + 10
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        for (int i = 1; i <= n; i++) {
            for (int j = res.size()-1; j >= 0; j--)
                res.push_back(res[j] + (1 << (i-1)));
        }
        return res;
    }
};