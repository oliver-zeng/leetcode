class Solution {
private:
    int nextNum(vector<int> &nums, int index) {
        int val = nums[index];
        for (int i = index + 1; i < nums.size(); i++)
            if (nums[i] != val)
                return i;
        return nums.size();
    }
    int preNum(vector<int> &nums, int index) {
        int val = nums[index];
        for (int i = index - 1; i >= 0; i--)
            if (nums[i] != val)
                return i;
        return -1;
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int sz = nums.size();
        if (sz < 4)
            return {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < sz - 3; i = nextNum(nums, i))
            for (int j = i + 1; j < sz - 2; j = nextNum(nums, j)) {
                int left = j + 1;
                int right = sz - 1;
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum > target)
                        right = preNum(nums, right);
                    else if (sum < target)
                        left = nextNum(nums, left);
                    else {
                        res.push_back(vector<int>({nums[i], nums[j], nums[left], nums[right]}));
                        left = nextNum(nums, left);
                        right = preNum(nums, right);
                    }
                }
            }
        return res;
    }
};
