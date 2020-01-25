class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        // 代码中有用到数组，就要确保当中的index不会有运行错误
        // memo[size-1]就要确保size >= 1
        if (size == 0) return 0;
        vector<int> memo(size, -1);
        memo[size-1] = nums[size-1];
        for (int i = size - 2; i >= 0; i--)
            // 代码中有数组，j范围是[i, size)，因为有memo[j+2]
            // 所以j < size 变为 (j+2) < size 即 j < size - 2
            // 但千万注意，不能够直接改在循环里，变为(int j =i; j < size - 2)
            // 哪儿说哪儿了，只作为memo[j+2]的额外判断条件即可
            // 否则在memo[j+2]不能取时，会连nums[j]也一同舍弃
            for (int j = i; j < size; j++)
            	memo[i] = max(memo[i], nums[j] + (j < size - 2 ? memo[j+2] : 0));
        return memo[0];
    }
};
