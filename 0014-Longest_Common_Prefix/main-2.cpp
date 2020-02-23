class Solution {
private:
    string solve(vector<string>& strs, int left, int right) {
        // 分治法的返回条件是
        // 对特定问题规模，进行直接求解
        if (left == right)
            return strs[left];

        // DivideConquer
        // 通过后序遍历，将多问题的规模，降低为两个问题
        // 改为求两个问题的解
        int mid = left + (right - left) / 2;
        string s1 = solve(strs, left, mid);
        string s2 = solve(strs, mid + 1, right);
        int i = 0;
        for (; i < s1.size() && i < s2.size(); i++)
            if (s1[i] != s2[i])
                break;

        // 无需再额外增加变量存储返回值
        // 直接通过index得到子串
        return s1.substr(0, i);
    }

public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            // 空字符串是""，而不是NULL
            return "";
        return solve(strs, 0, strs.size() - 1);
    }
};
