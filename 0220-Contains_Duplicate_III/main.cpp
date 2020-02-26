class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int left, right;
        left = right = 0;
        set<long long> record;
        for (; right < nums.size(); right++) {
            if (right - left > k)
                record.erase(nums[left++]);
            // the absolute difference between nums[i] and nums[j] is at most t
            // -t <= nums[right] - nums[left] <= t
            // 即 nums[right] - t <= nums[left] = nums[right] + t
            // 通过nums[right]找的是之前记录起来的nums[left]
            // loopup table 不一定是找 = target 的 key 那么精准
            // 使用非unordered_xx可以用lower_bound 找 >= target 的 key
            if (record.lower_bound((long long)nums[right] - (long long)t) != record.end()
                && *record.lower_bound((long long)nums[right] - (long long)t) <= (long long)nums[right] + (long long)t)
                return true;
            record.insert(nums[right]);
        }
        return false;
    }
};