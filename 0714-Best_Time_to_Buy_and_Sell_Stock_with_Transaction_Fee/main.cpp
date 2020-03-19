class Solution {
public:
    // 「选择」
    //   买buy、卖sell、什么都不做idle
    // 「选择状态」
    //   cash -> cash(idle)、stock(sell)
    //   stock -> stock(idle)、cash(buy)
    // 「问题状态」
    //   天数i，范围[0, prices.size() - 1]
    // 「状态转移方程」
    //   cash[i] = max(cash[i-1], stock[i-1] + prices[i] - fee)
    //   stock[i] = max(stock[i-1], cash[i-1] - prices[i])
    int maxProfit(vector<int>& prices, int fee) {
        int sz = prices.size();
        if (sz < 2)
            return 0;
        vector<int> cash(sz), stock(sz);
        cash[0] = 0;
        stock[0] = -prices[0];
        for (int i = 1; i < sz; i++) {
            cash[i] = max(cash[i-1], stock[i-1] + prices[i] - fee);
            stock[i] = max(stock[i-1], cash[i-1] - prices[i]);
        }
        return cash[sz-1];
    }
};