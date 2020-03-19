class Solution {
public:
    // 「选择」
    //   买buy、卖sell、什么都不做idle
    // 「选择状态」
    //   cash -> cooldown(idle)、cash(idle)
    //   stock -> cash(sell)、stock(idle)
    //   cooldown -> stock(buy)
    // 「问题状态」
    //   i天，范围 [0, prices.size() - 1]
    // 「状态转移方程」
    //   cash[i] = max (cash[i-1], stock[i-1] + prices[i])
    //   stock[i] = max (stock[i-1], cooldown[i-1] - prices[i])
    //   cooldown[i] = cash[i-1];
    // 「dp table空间优化」
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        if (sz < 2)
            return 0;
        vector<int> cash(sz), stock(sz), cooldown(sz);
        cash[0] = 0;
        stock[0] = -prices[0];
        cooldown[0] = 0;
        // 状态转移从略过 base case 开始
        for (int i = 1; i < prices.size(); i++) {
            cash[i] = max (cash[i-1], stock[i-1] + prices[i]);
            stock[i] = max (stock[i-1], cooldown[i-1] - prices[i]);
            cooldown[i] = cash[i-1];
        }
        return cash[sz - 1];
    }
};