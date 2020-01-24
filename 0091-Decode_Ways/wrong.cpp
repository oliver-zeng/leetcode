class Solution {
private:
    vector<vector<int>> memo;
    int calcNum(int index, int count, string &s) {
        if (s[index] == '0') return 0;
        if (memo[index][count] != -1) return memo[index][count];
        int num = atoi(s.substr(index, count).data());
        if (num >= 1 && num <= 10) return 1;
        if (num >= 11 && num <= 26) return 2;
        int res = 0;
        for (int i = 1; i <= count-1; i++)
            if (calcNum(index, i, s) == 0) {
                res = 0;
                break;
            } else
                res += calcNum(index, i, s);
        return memo[index][count] = res;
    }
public:
    int numDecodings(string s) {
        int size = s.size();
        memo = vector<vector<int>>(size+1, vector<int>(size+1, -1));
        return calcNum(0, size, s);
    }
};
