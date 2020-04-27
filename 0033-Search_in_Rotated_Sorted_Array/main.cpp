class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        // 搜索[left, right]当中的每一个数，while(left <= right)
        // 搜索[left, right)当中的每一个数，while(left < right)
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[left] <= nums[mid]) {
                // 有一边不是有序的，所以target必须跟left mid同时做比较，严格落在有序区间里
                //if (target <= nums[mid]) -> wrong
                if (target >= nums[left] && target <= nums[mid])
                    right = mid-1;
                else
                    left = mid+1;
            } else {
                //if (nums[mid] <= target)
                if (nums[mid] <= target && target <= nums[right])
                    left = mid+1;
                else
                    right = mid-1;
            }
        }
        return -1;
    }
};