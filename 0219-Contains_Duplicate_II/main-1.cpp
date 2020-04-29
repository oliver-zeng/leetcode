class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int left, right;
        left = right = 0;
        unordered_set<int> record;
        for (; right < nums.size(); right++) {
            // 依据题意滑块中最大允许数量是 k + 1
            // 所以[left, right]区间数量超过最大允许数量是
            // right - left + 1 > k + 1
            if (right - left > k)
                record.erase(nums[left++]);
            // {key, value}也能当key用，map与set数据结构一致
            // 操作时间复杂度一样，所以set其实没什么用？
            if (record.find(nums[right]) != record.end())
                return true;
            else
                record.insert(nums[right]);
        }
        return false;
    }
};