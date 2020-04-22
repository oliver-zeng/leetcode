class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int res = INT_MAX, sum = 0, count = 0;
        int left = 0, right = 0;
        while (right < nums.size()) {
            sum += nums[right];
            count++;
            while (sum >= s) {
                res = min(res, count);
                sum -= nums[left];
                left++;
                count--;
            }
            right++;
        }
        if (res == INT_MAX)
            return 0;
        return res;
    }
};