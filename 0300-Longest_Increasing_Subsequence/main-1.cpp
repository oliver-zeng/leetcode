class Solution {
private:
    vector<int> memo;
    // 以第index数字为结尾的最长LIS
    int calcLIS(vector<int> &nums, int index) {
        if (memo[index]) return memo[index];
        int res = 1;
        for (int i = 0; i < index; i++) {
            if (nums[index] > nums[i])
            	res = max(res, calcLIS(nums, i) + 1);
        }
        memo[index] = res;
        return res;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        if (0 == nums.size()) return 0;
        memo = vector<int>(nums.size(), 1);// 0
        //memo[0] = 1;
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
