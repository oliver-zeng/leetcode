class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sz = nums.size();
        if (sz <= 1)
            return sz;
        int slow = 0;
        for (int fast = 1; fast < sz; fast++) {
            if (nums[fast] == nums[fast-1])
                continue;
            nums[++slow] = nums[fast];
        }
        return slow + 1;
    }
};