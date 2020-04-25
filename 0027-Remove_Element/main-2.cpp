class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int sz = nums.size();
        if (sz == 0)
            return 0;
        int slow = -1;
        for (int fast = 0; fast < sz; fast++) {
            if (nums[fast] == val)
                continue;
            nums[++slow] = nums[fast];
        }
        return slow + 1;
    }
};