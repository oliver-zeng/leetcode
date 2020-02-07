#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
private:
    bool g_debug = true;
    vector<int> memo;
    int calcSquare(int n) {
        if (g_debug)
            cout << "[ " << n << " ] enter" << endl;
        if (n <= 0) return 0;
        //if (n == 1) return 1;
        if (memo[n] != -1) return memo[n];
        int res = INT_MAX;
        int i = 1;
        for (; i * i < n; i++) {
            if (g_debug)
                cout << "[ " << n << " ] : " << i * i << " + [ " << n - i * i << " ]" << endl;
            res = min(res, calcSquare(n - i * i) + 1);
        }
        // 这里不要漏掉 n 本身就是完全平方数的情况，此时返回的就是1
        if (i * i == n)
            res = 1;
        if (g_debug)
            cout << "[ " << n << " ] return " << res << endl;
        memo[n] = res;
        return res;
    }
public:
    int numSquares(int n) {
        memo = vector<int>(n + 1, -1);
        return calcSquare(n);
    }
};

//class Solution {
//private:
    //bool g_debug = true;
    //vector<int> memo;
    //int calcSquare(int n) {
        //if (g_debug)
            //cout << "[ " << n << " ] enter" << endl;
        //if (n <= 0) return 0;
        //if (n == 1) return 1;
        //if (memo[n] != -1) return memo[n];
        //int res = INT_MAX;
        //int i = 1;
        //for (; i * i < n; i++) {
        //if (g_debug)
            //cout << "[ " << n << " ] : " << i * i << " + [ " << n - i * i << " ]" << endl;
            //res = min(res, calcSquare(n - i * i) + 1);
        //if (g_debug)
            //cout << "[ " << n << " ] return " << res << endl;
        //}
        //if (i * i == n)
            //res = 1;
        //memo[n] = res;
        //return res;
    //}
//public:
    //int numSquares(int n) {
        //memo = vector<int>(n + 1, -1);
        //return calcSquare(n);
    //}
//};

int main() {
    cout << Solution().numSquares(12) << endl;
    return 0;
}
