class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0)
            return 0;
        int slow = 0, count = 0;
        for (int fast = 1; fast < sz; fast++) {
            if (nums[fast] == nums[fast-1])
                count++;
            else
                count = 0;
            if (count >= 2)
                continue;
            nums[++slow] = nums[fast];
        }
        return slow + 1;
    }
};