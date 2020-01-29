class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) return 0;
        // i遍历整个数组，k数组中最新要比较数的第一个位置
        int k = 0;
        for (int i = 1; i < sz; i++) {
            if (nums[i] == nums[k])
                continue;
            else
                swap(nums[i], nums[++k]);
        }
        return k + 1;
    }
};
