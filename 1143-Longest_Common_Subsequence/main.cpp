class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.size() == 0 || text2.size() == 0) return 0;
        vector<vector<int>> memo(2, vector<int>(text2.size()+1, 0));
        for (int i = 1; i <= text1.size(); i++)
            for (int j = 1; j <= text2.size(); j++){
                memo[i%2][j] = text1[i-1] == text2[j-1] ? memo[(i-1)%2][j-1] + 1: max(memo[(i-1)%2][j], memo[i%2][j-1]);
            }
        return memo[text1.size()%2][text2.size()];
    }
};
