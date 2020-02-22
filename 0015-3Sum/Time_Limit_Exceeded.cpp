// 虽然时间复杂度也是O(n^2)，但是超时了，nextNum用函数实现太费时间了
// 是用 while(l < r && nums[r--] == nums[cur])
// 和 while(l < r && nums[l++] == nums[cur])替代比较好
class Solution {
private:
    int nextNum(vector<int> &nums, int index) {
        int val = nums[index];
        for (int i = index; i < nums.size(); i++)
            if (nums[i] != val)
                return i;
        // 这里返回大于[0, nums.size())的值
        // 就可以不再进入循环了
        return nums.size();
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3)
            return {};
        sort(nums.begin(), nums.end());
        // 等于key的组合可能不止一个
        unordered_map<int, vector<pair<int, int>>> record;
        for (int i = 0; i < nums.size(); i = nextNum(nums, i))
            for (int j = i + 1; j < nums.size(); j = nextNum(nums, j))
                record[0 - nums[i] - nums[j]].push_back(make_pair(nums[i], nums[j]));

        vector<vector<int>> res;
        for (int i = 0; i < nums.size() - 2; i = nextNum(nums, i)) {
            if (nums[i] + nums[i+1] + nums[i+2] > 0)
                continue;

            if (record.find(nums[i]) == record.end())
                continue;

            auto iter = lower_bound(record[nums[i]].begin(), record[nums[i]].end(), make_pair(nums[i+1], nums[i+2]));
            for (; iter != record[nums[i]].end(); iter++)
                res.push_back({nums[i], iter->first, iter->second});
        }
        return res;
    }
};
