class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (0 == nums.size()) return 0;
        vector<int> memo = vector<int>(nums.size(), 1);// 0 -> wrong
        //memo[0] = 1; -> no need
        for (int i = 1; i < nums.size(); i++)
            for (int j = 0; j < i; j++)
                if(nums[i] > nums[j])
                    memo[i] = max(memo[i], memo[j]+1);
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
            res = max(res, memo[i]);
        return res;
    }
};
