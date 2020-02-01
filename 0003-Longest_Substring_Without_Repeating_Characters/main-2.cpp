#include<iostream>
#include<string>
using namespace std;

class Solution {
private:
    // 这里也可以用int类型，通过++&--得到的1&0，来作为true&false
    // ++&--的效率是要比赋值true&false效率高的
    bool used[256] = {false};
public:
    int lengthOfLongestSubstring(string s) {
        // 从左向右滑动，l应该是从0开始，[l, r]里面的元素个数一点点增加
        // 对每次新增元素判断是否重复（对应索引中数据不为-1）
        // 不重复，就直接r++把不重复元素加入滑动窗口[l, r]里
        // 若重复，还有再把l更新到前面重复元素后面的位置上
        // 滑动窗口不会漏解的原因是，l、r均自左向右遍历了
        // 只是通过判断减少了不符合题意的两两组合
        int l = 0, r = -1, res = 0;

        // int与unsigned int做运算，会都转换为unsigned int
        // 所以就会出现-1 > 8这种情形
        // the output is "a>b"
        //int a = -1; unsigned int b = 8;
        //if (a < b) cout << "a<b" << endl;
        //else cout << "a>b" << endl;
        // 同理，stl的size()方法返回值是unsigned int，所以必须要强制转化成int才能得到正确的值
        // 所以对于API的返回值，最好用int sz = s.size();接一下返回值，才不会出现隐式转换的错误
        //if (l<s.size()) cout << "l" << endl;
        //if (r<(int)( s.size() )) cout << "r" << endl;
        //else cout << "-1 > 8" << endl;

        // 滑块问题，只有在滑块[l, r]中，l移出才算全部找完
        // 并且滑块必须在if & else里切实的执行l & r的移动，否则会出现死循环
        while (l < s.size()) {
            if ((r + 1 < s.size()) && !used[s[r+1]])
                used[s[++r]] = true;
            else
                used[s[l++]] = false;

            res = max(res, r - l + 1);
        }

        return res;
    }
};

int main() {
    cout << Solution().lengthOfLongestSubstring("abcabcbb") << endl;
    return 0;
}
