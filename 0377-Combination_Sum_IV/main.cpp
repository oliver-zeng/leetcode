class Solution {
private:
    int res;
    void dfs(vector<int>& nums, int target) {
        if (target < 0)
            return;
        if (target == 0) {
            res++;
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (target < nums[i])
                continue;
            dfs(nums, target - nums[i]);
        }
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target+1, 0);
        // base case
        dp[0] = 1;
        for (int j = 1; j <= target; j++)
            for (int i = 0; i < nums.size(); i++) {
                if (j >= nums[i])
                    dp[j] += dp[j-nums[i]];
            }
        return dp[target];
    }
};