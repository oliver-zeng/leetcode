class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // nums[-1] = nums[n] = -∞
        // 所以只要不是升序，nums[0]就是peak
        // 当升序中途降序时，降前的 nums[i] 就是peak
        // 若一直是升序，则nums[sz-1]是peak
        int sz = (int)nums.size();
        for (int i = 0; i + 1 < sz; i++)
            if (nums[i] > nums[i+1])
                return i;
        return sz - 1;
    }
};