class Solution {
private:
    unordered_map<int, int> record;
    vector<vector<int>> res;
    vector<int> tmp;
    void dfs (vector<int> &nums, int step) {
        if (step == nums.size()) {
            res.push_back(tmp);
            return;
        }

        for (auto it = record.begin(); it != record.end(); it++) {
            //if (record.count(it->first)) {
            // key用过了就一定存在，find & count就恒能找到
            // 对于统计表来说，要看的是value是否为0，所以要判断的是second
            if (it->second) {
                it->second--;
                tmp.push_back(it->first);
                for (auto e : tmp)
                    cout << e << " ";
                cout << endl;
                dfs (nums, step + 1);
                tmp.pop_back();
                it->second++;
            }
        }

        return;
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for (auto elm : nums)
            record[elm]++;
        dfs (nums, 0);
        return res;
    }
};