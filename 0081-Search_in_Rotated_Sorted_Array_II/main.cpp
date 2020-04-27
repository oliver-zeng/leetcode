class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[left] < nums[mid]) {
                if (target >= nums[left] && target <= nums[mid])
                    right = mid-1;
                else
                    left = mid+1;
            } else if (nums[mid] < nums[right]) {
                if (target >= nums[mid] && target <= nums[right])
                    left = mid+1;
                else
                    right = mid-1;
            } else { // 有重复元素时，当 nums[left] == nums[mid] 时
                     // 无法判断 target 位于左侧还是右侧，此时无法缩小区间
                     // 因此要去掉，nums[left] == nums[mid] 时的干扰项
                // while的使用必须先确保不会越界
                // 这里必须有 left <= right，否则&&后面的index会越界
                while (left<=right && nums[left] == nums[mid])
                    left++;
                while (left<=right && nums[mid] == nums[right])
                    right--;
            }
        }
        return false;
    }
};