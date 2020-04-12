class Solution {
public:
    // 左右乘积
    // 将所有数字的乘积除以给定索引处的数字得到相应的答案
    // 然而这样的解决方法有一个问题，就是如果输入数组中出现 0，那么这个方法就失效了。
    // 可以利用索引处左侧的所有数字乘积和右侧所有数字的乘积相乘得到答案。
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = (int)nums.size();
        vector<int> left(sz);
        for (int i = 0; i < sz; i++) {
            if (i == 0)
                left[0] = 1;
            else
                left[i] = left[i-1] * nums[i-1];
        }
        // 由于输出数组不算在空间复杂度内，那么我们可以将 L 或 R 数组在用输出数组来计算，然后再动态构造另一个。
        // 不用构造 R 数组，从right[sz-1]开始由后向前，计算出每一个right[i]值临时存放进R
        // 把left[i] * right[i]的乘积直接存进left[i]用作输出即可
        int R = 1;
        for (int i = sz - 1; i >= 0; i--) {
            left[i] = left[i] * R;
            R *= nums[i];
        }
        return left;
    }
};