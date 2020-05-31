class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int sz = nums.size();
        // 要加为空的error handling
        if (sz == 0) return 0;
        vector<int> dp(sz, 1);
        int res = 1; // 这里初值应该为1，当只有一个数，无法进入循环时，结果就是1
        for (int i = 1; i < sz; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};