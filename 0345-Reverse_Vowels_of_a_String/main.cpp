#include<iostream>
#include<string>
using namespace std;

class Solution {
private:
    bool g_debug = false;
    bool isVowels(char c) {
        c = tolower(c);
        if ((c == 'a') || (c == 'e') ||
           (c == 'i') || (c == 'o') || (c == 'u'))
            return true;
        else
            return false;
    }
public:
    string reverseVowels(string s) {
        int sz = s.size();
        int l = 0, r = sz - 1;
        while (l < r) {
            if (g_debug) {
                cout << "l pos " << l << " s[l] " << s[l] << endl;
                cout << "r pos " << r << " s[r] " << s[r] << endl;
            }
            while((l<sz) && !isVowels(s[l])) {
                l++;
            }
            while((r >= 0) && !isVowels(s[r])) {
                r--;
            }
            // 这里必须要有l & r的移动
            // 否则前两个判断isVowels都是true，都没进去的话，就直接死循环了
            if (l < r)
                swap(s[l++], s[r--]);

        }
        return s;
    }
};
int main() {
    Solution().reverseVowels("hello");

    return 0;
}
