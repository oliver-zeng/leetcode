#include<iostream>
#include<string>
#include<cassert>
using namespace std;

class Solution {
private:
    bool g_debug = true;
    // 直接用现成的std::isalnum，返回0不是数字或字母
    bool isAlphanum (char c) {
        if (( ('0' <= c) && (c <= '9') ) ||
            ( ('a' <= c) && (c <= 'z') ) ||
            ( ('A' <= c) && (c <= 'Z') ))
            return true;
        else
            return false;
    }
public:
    bool isPalindrome(string s) {
        int sz = s.size();
        int l = 0, r = sz - 1;
        // 偶数正好比完中间两个，奇数中间一个不用看
        while (l < r) {
            if (g_debug) {
                cout << "l s[" << l << "] " << s[l] << endl;
                cout << "r s[" << r << "] " << s[r] << endl;
            }

            if (!isAlphanum(s[l])) {
                l++;
            } else if (!isAlphanum(s[r])) {
                r--;
            } else {
                assert(isAlphanum(s[l]) && isAlphanum(s[r]));
                // tolower遇到非字母是不会转换的，所以前面的判断条件可去掉
                // if(tolower(s[l]) != tolower(s[r]))就够了
                if ((s[l] != s[r]) && (tolower(s[l]) != tolower(s[r]))) {
                    if (g_debug) cout << "flase" << endl;
                    return false;
                }
                else {
                    l++;
                    r--;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution().isPalindrome("race a car");
}
