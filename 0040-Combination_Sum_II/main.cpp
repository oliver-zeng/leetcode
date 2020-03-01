class Solution {
private:
    vector<vector<int>> res;
    vector<int> tmp;
    int nextNum(vector<int>& candidates, int begin) {
        for (int i = begin + 1; i < candidates.size(); i++) {
            if (candidates[i] != candidates[begin])
                return i;
        }
        return candidates.size();
    }

    void chooseNum(vector<int>& candidates, int target, int begin) {
        // 每次target - candidates[i]都是大于等于0的
        // 所以不会出现target < 0的情况
        if (target == 0) {
            res.push_back(tmp);
            return;
        }

        for (int i = begin; i < candidates.size(); i = nextNum(candidates, i)) {
            if (candidates[i] <= target) {
                tmp.push_back(candidates[i]);
                chooseNum(candidates, target - candidates[i], i + 1);
                tmp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // 组合问题，同样的数字，顺序不管如何改变，都是同一个组合
        // 因此对于每一个阶段来说，每次取到的数字，都应该是不同的
        sort (candidates.begin(), candidates.end());
        chooseNum(candidates, target, 0);
        return res;
    }
};