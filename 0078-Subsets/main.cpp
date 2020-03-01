class Solution {
private:
    vector<vector<int>> res;
    vector<int> tmp;
    void dfs (vector<int> &nums, int sz, int index) {
        if (sz == tmp.size()) {
            res.push_back(tmp);
            return;
        }
        
        for (int i = index; i < nums.size(); i++) {
            // [index, nums.size())
            if (nums.size() - index < sz - tmp.size())
                break;
            tmp.push_back(nums[i]);
            dfs (nums, sz, i + 1);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        for (int sz = 0; sz <= nums.size(); sz++)
            dfs (nums, sz, 0);
        return res;
    }
};