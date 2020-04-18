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
        if (n == 0)
            return {0};
        vector<int> res = {0, 1};
        for (int i = 2; i <= n; i++) {
            vector<int> tmp(2 * res.size());
            copy(res.begin(), res.end(), tmp.begin());
            copy(res.rbegin(), res.rend(), tmp.begin() + res.size());
            for (int j = res.size(); j < tmp.size(); j++)
                tmp[j] += 1 << (i-1);
            res = tmp;
        }
        return res;
    }
};