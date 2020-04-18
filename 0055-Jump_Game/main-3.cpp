class Solution {
public:
    bool canJump(vector<int>& nums) {
        int sz = (int)nums.size();
        int pre = nums[0];
        for (int i = 1; i < sz; i++)
            if (pre >= i)
                pre = max(pre, i+nums[i]);
        if (pre >= sz-1)
            return true;
        return false;
    }
};