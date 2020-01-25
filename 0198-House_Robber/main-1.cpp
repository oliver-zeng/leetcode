class Solution {
private:
    vector<int> memo;
    int calcRob(vector<int> &nums, int start, vector<int> &memo) {
        int size = nums.size();
        if (start >= size) return 0;
        if (-1 != memo[start]) return memo[start];
        int res = 0;
        for (int i = start; i < size; i ++) {
            res = max(res, nums[i] + calcRob(nums, i + 2, memo));
        }
        memo[start] = res;
        return res;
    }
public:
    int rob(vector<int>& nums) {
        memo = vector<int>(nums.size(), -1);
        return calcRob(nums, 0, memo);
    }
};
