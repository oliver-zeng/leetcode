class Solution {
private:
    int sz;
    vector<int> memo;
    // calcProfit是在prices[0 : index]区间的最优价格
    int calcProfit(vector<int>& prices, int index) {
        if (index < 0) return 0;
        if (memo[index] != -1) return memo[index];
        // 不选
        int res = calcProfit(prices, index - 1);
        // 选
        int profit = 0;
        for (int i = 0; i < index; i++) {
            profit = prices[index] - prices[i];
            if (profit > 0) // 有的赚
                res = max(res, calcProfit(prices, i - 2) + profit);
        }
        return memo[index] = res;
    }
public:
    int maxProfit(vector<int>& prices) {
        // 排序问题，无非也是选与不选的问题
        // 只不过相比组合，还有一个顺序的影响，在选了的情况下，
        // 需要研究所选index与前面索引的最优子问题有何种关联
        sz = prices.size();
        memo = vector<int>(sz, -1);
        return calcProfit(prices, sz - 1);
    }
};
