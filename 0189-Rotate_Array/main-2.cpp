class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int sz = nums.size();
        k %= sz;
        // 三次翻转
        // 原始数组                  : 1 2 3 4 5 6 7
        // 反转所有数字后             : 7 6 5 4 3 2 1
        // 反转前 k 个数字后          : 5 6 7 4 3 2 1
        // 反转后 n-k 个数字后        : 5 6 7 1 2 3 4 --> 结果
        reverse(&nums[0], &nums[sz]);
        reverse(&nums[0], &nums[k]);
        reverse(&nums[k], &nums[sz]);
    }
};