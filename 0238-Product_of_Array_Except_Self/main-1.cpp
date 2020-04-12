class Solution {
public:
    // 左右乘积法
    // 将所有数字的乘积除以给定索引处的数字得到相应的答案
    // 但这样的解决方法有一个问题，就是如果输入数组中出现 0，那么这个方法就失效了
    // 所以要避免使用除法，利用索引处左侧的所有数字乘积和右侧所有数字的乘积相乘得到答案
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = (int)nums.size();
        vector<int> left(sz);
        vector<int> right(sz);
        for (int i = 0; i < sz; i++) {
            if (i == 0)
                left[0] = 1;
            else
                left[i] = left[i-1] * nums[i-1];
        }
        for (int i = sz - 1; i >= 0; i--) {
            if (i == sz - 1)
                right[sz-1] = 1;
            else
                right[i] = right[i+1] * nums[i+1];
        }
        vector<int> res(sz);
        for (int i = 0; i < sz; i++)
            res[i] = left[i] * right[i];
        return res;
    }
};