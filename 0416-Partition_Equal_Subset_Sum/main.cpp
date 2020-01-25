class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++)
            sum += nums[i];
        if (sum % 2) return false;
        // vector<vector<int>>无论怎样嵌套，都是一个vector类型T
        // vector的类型T初始化是T(n, val)，n个元素，每个值为val
        // val可以是任一类型，若也是vector类型，则再使用T'(n, val')的方式对val进行赋初值
        vector<bool> memo((sum>>1)+1);
        for (int col = 0; col <= sum>>1; col++)
            memo[col] = (nums[0] == col) ? true : false;

        for (int row = 1; row <= size - 1; row++)
            for (int col = sum>>1; col >= nums[row]; col--)
                memo[col] = memo[col] || memo[col-nums[row]];
        return memo[sum>>1];
    }
};
