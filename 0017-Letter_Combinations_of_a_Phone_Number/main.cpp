#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

class Solution {
private:
    bool g_debug; // = true;

    // 数组元素赋初值，用逗号隔开，最后一个元素没有逗号
    // {}用于数组元素，或结构体赋初值
    string transfer[10] = {
        "",	// 0
        "",	// 1
        "abc",	// 2
        "def",	// 3
        "ghi",	// 4
        "jkl",	// 5
        "mno",	// 6
        "pqrs",	// 7
        "tuv",	// 8
        "wxyz"	// 9
    };

    vector<string> res;
    int max_index;

    // tmp里记录的是[0, index-1]的字符串，现在要讨论的是digits[index]翻译出的字符
    void represent(string &digits, int index, const string &tmp) {
        // 在递归调用一开始把每次递归调用的参数打出来
        if (g_debug)
            cout << index << " : " << tmp << endl;
        if (index == max_index) {
            res.push_back(tmp);
            // 在递归调用结束准备返回前，把递归树到叶子后得到的返回结果打出来
            if (g_debug)
                cout << "get " << tmp << " return" << endl;
            return;
        }
        int num = transfer[digits[index] - '0'].size();

        // 分别在分叉前后打log，展示回溯过程
        for (int i = 0; i < num; i++) {
            // 在递归自身调用前，把递归选择的分支打出来
            if (g_debug)
                cout << "digits[" << index << "] = " << digits[index] << " use " << transfer[digits[index] - '0'][i] << endl;
            represent (digits, index + 1, tmp + transfer[digits[index] - '0'][i]);
        }
        // 在递归调用结束准备回溯时，把要回溯的递归树节点位置打出来
        if (g_debug)
            cout << "digits[" << index << "] = " << digits[index] << " done, recall " << endl;
        return;
    }

public:
    vector<string> letterCombinations(string digits) {
        max_index = digits.size();
        res.clear();
        if (max_index == 0) return res;
        represent(digits, 0, "");
        return res;
    }
};

// 测试用例
void printVec(const vector<string>& vec){
    for(string s: vec)
        cout << s << endl;
}

int main() {
    printVec(Solution().letterCombinations("23"));
}
