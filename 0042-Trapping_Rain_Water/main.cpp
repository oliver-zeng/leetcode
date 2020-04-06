class Solution {
public:
    int trap(vector<int>& height) {
        int sz = height.size();
        if (sz < 2)
            return 0;
        // left_max[i]是[0, i]上的最大值
        // right_max[i]是[i, sz-1]上的最大值
        vector<int> left_max(sz), right_max(sz);
        left_max[0] = height[0];
        for (int i = 1; i < sz; i++)
            left_max[i] = max(left_max[i-1], height[i]);
        right_max[sz-1] = height[sz-1];
        for (int i = sz - 2; i >= 0; i--)
            right_max[i] = max(right_max[i+1], height[i]);
        // 从第二个到倒数第二个点，逐一计算
        // 以i两边最大值的最小值，在i处盛的水
        int sum = 0;
        for (int i = 1; i < sz - 1; i++)
            sum += min(left_max[i], right_max[i]) - height[i];
        return sum;
    };
};