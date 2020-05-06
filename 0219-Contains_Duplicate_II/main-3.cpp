class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;
        int i = 0, j = 0;
        while (j < nums.size()) {
            if (j - i > k)
                window.erase(nums[i++]);
            if (window.count(nums[j]))
                return true;
            else
                window.insert(nums[j]);
            j++;
        }
        return false;
    }
};