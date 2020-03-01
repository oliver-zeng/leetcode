class Solution {
private:
    vector<vector<int>> res;
    vector<int> tmp;
    void chooseNum(int k, int target, int step, int num) {
        if (k == step) {
            // 根据每次选择后产生的结果来确定递归结束条件
            if (target == 0)
                res.push_back(tmp);
            return;
        }

        for (int i = num; i <= 9; i++) {
            // 组合问题在每次选出数字后，要先判断数字是否可用
            if (i > target)
                break;
            tmp.push_back(i);
            // 这题每个数字最多只能用一次，组合问题一定要先问清每个数字能用几次
            chooseNum(k, target - i, step + 1, i+1);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        chooseNum(k, n, 0, 1);
        return res;
    }
};