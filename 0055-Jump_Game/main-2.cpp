class Solution {
public:
    bool canJump(vector<int>& nums) {
        int sz = (int)nums.size();
        vector<int> dp(sz);
        dp[0] = nums[0];
        for (int i = 1; i < sz; i++)
            for (int j = i - 1; j >= 0; j--)
                // 只要有子问题的最远距离可以达到原问题
                // 那么原问题能到达的最远距离就是：
                // 原问题点起始位置 + 从原问题开始跳能到的最远距离
                if (dp[j] >= i) {
                    dp[i] = i+nums[i];
                    break;
                }
        if (dp[sz-1] >= sz-1)
            return true;
        return false;
    }
};