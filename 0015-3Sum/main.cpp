class Solution {
private:
    // 去重的关键是，指向每个数字的指针前后顺序固定
    // 排完序后，每个指针各自对于同一个值的数据，只会访问一次
    int preNum(vector<int> &nums, int index) {
        int val = nums[index];
        for (int i = index - 1; i > 0; i--)
            if (nums[i] != val)
                return i;
        return -1;
    }
    int nextNum(vector<int> &nums, int index) {
        int val = nums[index];
        for (int i = index + 1; i < nums.size(); i++)
            if (nums[i] != val)
                return i;
        return nums.size();
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int sz = nums.size();
        if (sz < 3)
            return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < sz - 2; i = nextNum(nums, i)) {
            int left = i + 1, right = sz - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum > 0)
                    right = preNum(nums, right);
                else if (sum < 0)
                    left = nextNum(nums, left);
                else { // sum == 0
                    res.push_back(vector<int>({nums[i], nums[left], nums[right]}));
                    left = nextNum(nums, left);
                    right = preNum(nums, right);
                }
            }
        }
        return res;
    }
};
