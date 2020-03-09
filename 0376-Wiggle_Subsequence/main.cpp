class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int sz = nums.size();
        if (sz < 2)
            return sz;
        // up以nums[i]升序结尾的最长wiggle sequence
        vector<int> up(sz, 1);
        // down以nums[i]降序结尾的最长wiggle sequence
        vector<int> down(sz, 1);
        // 计算 up & down
        for (int i = 1; i < nums.size(); i++)
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j])
                    up[i] = max(up[i], down[j] + 1);
                else if (nums[i] < nums[j])
                    down[i] = max(down[i], up[j] + 1);
            }
        // 遍历所有结果，获取最大max
        int res = 0;
        for (int i = 0; i < sz; i++)
            res = max(res, max(up[i], down[i]));
        return res;
    }
};class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int sz = nums.size();
        if (sz < 2)
            return sz;
        // up以nums[i]升序结尾的最长wiggle sequence
        vector<int> up(sz, 1);
        // down以nums[i]降序结尾的最长wiggle sequence
        vector<int> down(sz, 1);
        // 计算 up & down
        for (int i = 1; i < nums.size(); i++)
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j])
                    up[i] = max(up[i], down[j] + 1);
                else if (nums[i] < nums[j])
                    down[i] = max(down[i], up[j] + 1);
            }
        // 遍历所有结果，获取最大max
        int res = 0;
        for (int i = 0; i < sz; i++)
            res = max(res, max(up[i], down[i]));
        return res;
    }
};