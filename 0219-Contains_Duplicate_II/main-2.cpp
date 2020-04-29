class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> dict; // nums[i], i
        for (int i = 0; i < nums.size(); i++) {
            // dict[nums[i]]是先加入了，所以一定是i>dict[nums[i]]
            if (dict.count(nums[i]) && i - dict[nums[i]] <= k)
                return true;
            // 有多个index里有相同值，更新最后的index就可以
            // 因为新找到的是最后的一个index，记录的是倒数第二个index
            // 对于新找到的index，记录的index距离肯定是比更靠前的index要近的
            dict[nums[i]] = i;
        }
        return false;
    }
};