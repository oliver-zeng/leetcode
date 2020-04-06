class Solution {
public:
    // 「问题状态」
    //   天数i，范围[0, prices.size()-1]，有限次需要记录
    //   交易次数j，范围[0, 2]，有限次需要记录
    // 「选择 & 结果」
    //   买buy -> -prices[i]，状态变为stock
    //   卖sell -> prices[i]，状态变为cash
    //   什么都不做idle -> 0，状态不变
    // 「选择状态」
    //   持有stock，sell & idle；未持有cash，buy & idle
    //   当前问题i的选择，需要知道之前的选择状态，所以需要stock、cash两个table
    // 「状态转移」
    //   stock[i][j] = max(stock[i-1][j], cash[i-1][j-1] - prices[i]);
    //   sell[i][j] = max(sell[i-1][j], stock[i-1][j] + prices[i]);
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        if (sz <= 1)
            return 0;
        vector<vector<int>> stock(sz, vector<int>(3)), cash(sz, vector<int>(3));
        for (int i = 0; i < sz; i++) {
            cash[i][0] = 0;
            stock[i][0] = -prices[0]; // 给的是正确解的一个小值，毕竟不可能的负无穷不可能取到
        }
        for (int j = 0; j <= 2; j++) {
            cash[0][j] = 0;
            stock[0][j] = -prices[0]; // 给的是正确解的一个小值，毕竟不可能的负无穷不可能取到
        }
        for (int i = 1; i < sz; i++)
            for (int j = 1; j <= 2; j++) {
                stock[i][j] = max(stock[i-1][j], cash[i-1][j-1] - prices[i]);
                cash[i][j] = max(cash[i-1][j], stock[i-1][j] + prices[i]);
            }
        return cash[sz-1][2];
    }
};