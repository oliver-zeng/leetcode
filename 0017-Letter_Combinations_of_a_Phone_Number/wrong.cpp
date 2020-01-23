class Solution {
private:
    // 数组元素赋初值，用逗号隔开，最后一个元素没有逗号
    // {}用于数组元素，或结构体赋初值
    string transfer[10] = {
        "",		// 0
        "",		// 1
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
    // 1
    void represent(string &digits, int index, const string &tmp) {
        char c = digits[index];
        //int num = transfer[digits[index] - '0'].size();
        assert (c >= '0' && c<='9');
        int num = transfer[c - '0'].size();

        if (index == max_index) {
            res.push_back(tmp);
            return;
        }
        for (int i = 0; i < num; i++) {
            represent (digits, index + 1, tmp + transfer[digits[index] - '0'][i]);
        }
        return;
    }

public:
    vector<string> letterCombinations(string digits) {
        max_index = digits.size();
        represent(digits, 0, "");
        return res;
    }
};


