class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sz = nums.size();
        if (sz < 3)
            return -1;
        sort(nums.begin(), nums.end());
        // 因为用的对撞指针，diff初值无论取极大，还是极小值
        // 都会影响left与right的正常走向，所以干脆直接算一个真的
        // 然后正常找就是了，无法是有可能会重复找到提前写好的这一个罢了
        int res = nums[0] + nums[1] + nums[2];
        int diff = abs(target - res);
        for (int i = 0; i < sz - 2; i++) {
            int left = i + 1;
            int right = sz - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                // 只有尽可能向着使target = sum的方向移动双指针
                // 才可能使diff尽可能趋近于0
                if (diff > abs(target - sum)) {
                    res = sum;
                    diff = abs(target - sum);
                }
                if (sum > target)
                    right--;
                else if (sum < target)
                    left++;
                else // sum == target 已经找到直接返回
                    return res;
            }
        }
        return res;
    }
};
