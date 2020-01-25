class Solution {
private:
    vector<vector<int>> memo;
    int wsize;
    int calcBreak (int m, int n, string &s, vector<string>& wordDict) {
        if ( m > n ) return 0;
        if (memo[m][n] != -1) return memo[m][n];
        for (int i = 0; i < wsize; i++)
            if (s.substr(m, n - m + 1) == wordDict[i])
                return memo[m][n] = 1;
        memo[m][n] = 0;
        for (int i = m; i <= n; i++) {
            if ((calcBreak(m, i, s, wordDict) == 1) &&
                (calcBreak(i + 1, n, s, wordDict) == 1)) {
                	memo[m][n] = 1;
                	break;
            }
        }
        return memo[m][n];
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.size();
        wsize = wordDict.size();
        memo = vector<vector<int>>(size, vector<int>(size, -1));
        return calcBreak(0, size - 1, s, wordDict) == 1;
    }
};
