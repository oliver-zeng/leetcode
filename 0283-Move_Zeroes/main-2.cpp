class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int sz = nums.size();
        // i遍历全部元素，writable_pos是下一个正确元素要放的位置
        // 只要所有正确的i都按照顺序，放到writable_pos++的位置，就能保证数字顺序不变的都放到前面
        // 同时，因为不正确i的位置，没有变，早晚会被正确的i换到后面去
        // 但是在最开始全是正确时的交换是没有意义的，即writable_pos=i时没必要做无意义的交换
        int writable_pos = 0;
        for (int i = 0; i < sz; i++) {
            if (nums[i])
                if (i != writable_pos)
                    swap(nums[writable_pos++], nums[i]);
                else
                    writable_pos++;
        }
    }
};
