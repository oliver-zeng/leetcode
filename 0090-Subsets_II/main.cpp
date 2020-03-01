class Solution {
private:
    vector<vector<int>> res;
    vector<int> tmp;
    int nextNum(vector<int> &nums, int index) {
        for (int i = index + 1; i < nums.size();i ++)
            if (nums[i] != nums[index])
                return i;
        return nums.size();
    }
    void dfs (vector<int> &nums, int sz, int index) {
        if (sz == tmp.size()) {
            res.push_back(tmp);
            return;
        }
        for (int i = index; i < nums.size(); i = nextNum(nums, i)) {
            if (nums.size() - i < sz - tmp.size())
                break;
            tmp.push_back(nums[i]);
            dfs (nums, sz, i + 1);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort (nums.begin(), nums.end());
        for (int sz = 0; sz <= nums.size(); sz++)
            dfs (nums, sz, 0);
        return res;
    }
};