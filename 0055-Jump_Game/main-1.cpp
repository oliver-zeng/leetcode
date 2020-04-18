class Solution {
public:
    bool canJump(vector<int>& nums) {
        int sz = (int)nums.size();
        vector<bool> dp(sz);
        dp[0] = true;
        for (int i = 1; i < sz; i++)
            // for (int j = 0; j < i; j++) {
            //从后往前，可以减低复杂度
            for (int j = i-1; j >= 0; j--) {
                if (dp[j] && j+nums[j] >= i) {
                    dp[i] = true;
                    break;
                }
            }
        return dp[sz-1];
    }
};