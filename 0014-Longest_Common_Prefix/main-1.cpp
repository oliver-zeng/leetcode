class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int sz = strs.size();
        string res = "";
        char c;

        if (strs.size() == 0)
            return res;

        // 双重循环下标的含义不同
        // 第一重，i是字符串strs[0]中的索引
        for (int i = 0; i < strs[0].size(); i++) {
            c = strs[0][i];
            // 第二重，j是strs中多个串的索引
            for (int j = 1; j < strs.size(); j++)
                // 这题暴力解难点，在于string[index]的越界条件
                // 同数组一样，判断连续存储空间是否越界，要看空间长度
                if (i >= strs[j].size() || strs[j][i] != c)
                    return res;

            res += c;
        }

        return res;
    }
};
