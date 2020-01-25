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
        if (index < 0) return 1; // 相当于正好处理完整个字串s，所以是1个解
        if (index == 0) {
            if ((s[0] - '0') == 0) return 0;
            else return 1;
        }

        if (memo[index] != -1) return memo[index];

        if (s[index] - '0' != 0) memo[index] = calcDec(s, index - 1);
        else memo[index] = 0;

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
