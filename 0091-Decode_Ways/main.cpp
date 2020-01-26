#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
private:
    int sz;
    vector<int> memo;
    int calcDec(string &s, int index) {
        int n;
        int res;
        // 直接按越界条件返回，就不需要为index + 2写index == 1的赋初值了
        // 相当于正好处理完整个字串s，所以是1个解
        if (index < 0) return 1;
        if (index == 0) {
            if ((s[0] - '0') == 0) return 0;
            else return 1;
        }

        if (memo[index] != -1) return memo[index];

        // 跟顺序有关，所以要找到是index与[0, index - 1]中解的关系
        // 在写递归方程式时，要直接以实例来写，列出实例中的每一个解来找关系
        // 否则想当然，很容易想成"123"的解是"1"的解乘以"23"的解，但这实际上是错的：
        // "1"		=> {"1"}
        // "12"		=> {"1","2"}, {"12"}
        // "123"	=> {"1","2","3"},{"12","3"},{"1","23"}
        // 从"12"到"123"多出来的字符"3"只会接在"12"解的后面
        // 只有与前面结合成"23"才是多出来的解

        // 另外这题的难点在于实际写递归表达式时，对实际得到的一位数&两位数都需要分类讨论：

        // 一位数
        // 若为0没法直接接在之前解的后面，只能看结合成两位数看能不能有解
        if (s[index] - '0' != 0) memo[index] = calcDec(s, index - 1);
        else memo[index] = 0;

        // 两位数
        // 结合出的"00"根本没有解
        // 结合出的[1,9]没有以0开头如"01"可以decode的字母，不能结合
        // 只能说拆开的，不会多出解
        // 只有[10, 26]才有可以decode的字母，会多出解
        n = atoi(s.substr(index - 1, 2).data());
        if (n == 0) memo[index] = 0;
        else if (n >= 10 && n <= 26) memo[index] += calcDec(s, index - 2);

        return memo[index];
    }
public:
    int numDecodings(string s) {
        sz = s.size();
        memo = vector<int>(sz, -1);
        return calcDec(s, sz - 1);
    }
};

int main() {
    cout << Solution().numDecodings("101");
    return 0;
}
