class Solution {
private:
    vector<int> tmp;
    vector<vector<int>> res;
    void findTarget(vector<int>& candidates, int target, int begin) {
        if (target < 0)
            return;

        if (target == 0) {
            res.push_back(tmp);
            return;
        }

        // 组合问题，要考虑选择的顺序，后选的不能选得比前面选的位置还靠前
        for (int i = begin; i < candidates.size(); i++) {
            if (candidates[i] > target)
                continue;
            tmp.push_back(candidates[i]);
            // 注意这里每个数字可以选多次，所以当前选择i了，后面还可以从i开始选
            findTarget(candidates, target - candidates[i], i);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        findTarget(candidates, target, 0);
        return res;
    }
};