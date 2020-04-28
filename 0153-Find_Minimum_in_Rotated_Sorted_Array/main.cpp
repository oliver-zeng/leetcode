#define CHECK_LEFT
class Solution {
public:
    int findMin(vector<int>& nums) {
    #ifdef CHECK_LEFT // 多了判断速度慢
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            // 用左边来判断会比较麻烦的原因是，[left, mid]升序时，无法判定，原因是：
            // 若[mid, right]也升序，则最小值在左半区，为nums[left]
            // 若[mid, right]不是升序，则最小值在右半区
            int mid = left + (right - left) / 2;
            if (nums[left] <= nums[mid]) {
                if (nums[mid] <= nums[right])
                    return nums[left];
                else
                    left = mid+1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    #else // check right
        int left = 0, right = nums.size() - 1;
        // 二分查找秘诀是，是通过mid来划分半区，永远确保要找的元素在[left, right]或[left, right)里
        // 另一个是循环条件与right移动有关，与查找区间是否为开区间[left, right]或[left, right)无关
        // left = mid+1, right = mid-1 对应的循环条件是while(left <= right)
        // left = mid+1, right = mid 对应的循环条件是 while(left < right)
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= nums[right])
                right = mid;
            else
                left = mid + 1;
        }
        // while(left < right)结束时left = right，此时只剩一个元素
        // 最小值始终在里面，所以这个剩下的就是最小值
        return nums[right];
    #endif
    }
};