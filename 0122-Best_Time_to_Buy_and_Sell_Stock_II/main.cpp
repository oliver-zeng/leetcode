class Solution {
    // 「问题状态」
    //   需要几个变量（状态）才能将原问题描述清楚，这决定了dp table的维度
    //   天数，第i天的最大利润
    // 「选择」
    //   有三种：买入(buy)、卖出(sell)、什么都不做(idle)
    // 「选择状态」
    //   影响选择的因素，即什么状态下可以做选择，这决定了需要几个dp table
    //   持有状态，持有时(stock)才能卖，卖出后(crash)才能买
    // 「状态转移方程」
    //   stock[i] = max( stock[i-1], crash[i-1] - prices[i-1] )
    //   crash[i] = max( crash[i-1], stock[i-1] + prices[i-1] )
    // 「bsse case」
    //   各 dp table 在问题状态最小值时的初值
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        if (!sz) return 0;
        vector<int> crash(sz), stock(sz);
        crash[0] = 0;           // 持有现金，利润为0
        stock[0] = -prices[0];  // 买入股票，利润为 -prices[0]
        for (int i = 1; i < sz; i++) {
            // 在第i天持有现金的最大利润是：
            // 从前一天持有现金到今天 或 将前一天持有的股票在今天卖出，这两个选择里的最大值
            crash[i] = max ( crash[i-1], stock[i-1] + prices[i] );
            // 在第i天持有股票的最大利润是：
            // 从前一天持有股票到今天 或 将前一天的现金在今天买成股票，这两个选择里的最大值
            stock[i] = max ( stock[i-1], crash[i-1] - prices[i] );
        }
        return crash[sz - 1];
    }
};class Solution {
    // 「问题状态」
    //   需要几个变量（状态）才能将原问题描述清楚，这决定了dp table的维度
    //   天数，第i天的最大利润
    // 「选择」
    //   有三种：买入(buy)、卖出(sell)、什么都不做(idle)
    // 「选择状态」
    //   影响选择的因素，即什么状态下可以做选择，这决定了需要几个dp table
    //   持有状态，持有时(stock)才能卖，卖出后(crash)才能买
    // 「状态转移方程」
    //   stock[i] = max( stock[i-1], crash[i-1] - prices[i-1] )
    //   crash[i] = max( crash[i-1], stock[i-1] + prices[i-1] )
    // 「bsse case」
    //   各 dp table 在问题状态最小值时的初值
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        if (!sz) return 0;
        vector<int> crash(sz), stock(sz);
        crash[0] = 0;           // 持有现金，利润为0
        stock[0] = -prices[0];  // 买入股票，利润为 -prices[0]
        for (int i = 1; i < sz; i++) {
            // 在第i天持有现金的最大利润是：
            // 从前一天持有现金到今天 或 将前一天持有的股票在今天卖出，这两个选择里的最大值
            crash[i] = max ( crash[i-1], stock[i-1] + prices[i] );
            // 在第i天持有股票的最大利润是：
            // 从前一天持有股票到今天 或 将前一天的现金在今天买成股票，这两个选择里的最大值
            stock[i] = max ( stock[i-1], crash[i-1] - prices[i] );
        }
        return crash[sz - 1];
    }
};