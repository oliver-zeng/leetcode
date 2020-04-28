class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            // 右半区为升序：
            // 若左半区不为升序，则最小值在左半边
            // 若左半区为升序，则最小值就是nums[mid]
            // 因此 right = mid 才能不丢最小值
            if (nums[mid] < nums[right])
                right = mid;
            // 右半区不为升序，则最小值一定在右半区 left = mid + 1，mid 可以丢弃
            else if (nums[mid] > nums[right])
                left = mid+1;
            else {
                // right不可能等于mid，否则就是left = right已经跳出循环了
                // 所以right最小也是mid+1，right--消除的只是重复的数，不会减掉最小值，不影响查找的正确性
                right--;
            }
        }
        return nums[left];
    }
};