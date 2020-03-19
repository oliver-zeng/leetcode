class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // 「选择」：
        //   买入(buy)、卖出(sell)、什么都不做(idle)
        // 「选择状态」：
        //   stock -> sell / idle 或 cash -> buy / idle
        // 「问题状态」：
        //   股市的天数 i，范围 [0, prices.size() - 1] 天
        //   最多交易次数 j，范围 [0, j] 次
        //  （一次买卖是一次交易，买进计一次交易，卖出属于这次交易内，即仅cash执行sell时交易加1）
        // 「状态转移方程」：
        //   cash[i][j] = max ( cash[i-1][j], stock[i-1][j] - prices[i] )
        //   j只有在buy的时候才会加1，后一个状态j，由前一个状态j-1得来
        //   stock[i][j] = max ( stock[i-1][j], cash[i-1][j-1] + prices[i] )
        int sz = prices.size();
        if (sz < 2) return 0;
        // sz 个元素，最多进行 sz/2 次交易，所以 k 足够大时，相当于没有交易限制
        // 根本不需要用 memo ，就不用担心以过大的 k 来建 memo 会造成 memory leak 了
        if (k > sz/2) {
            int res = 0;
            for (int i = 1; i < sz; i++)
                if (prices[i] > prices[i-1])
                    res += prices[i] - prices[i-1];
            return res;
        }
        vector<vector<int>> cash(sz, vector<int>(k+1)), stock(sz, vector<int>(k+1));
        /*
        只把所有维度都取最小值来赋初值是不够的，
        比如下面只为全维度的最小值赋值
        stock[0][1] = -prices[0];
        cash[0][0] = 0;
        cash[0][1] = 0;
        stock[1][2] 会用到 stock[0][2] cash[0][1]
        stock[1][3] 会用到 stock[0][3] cash[0][2]
        所以必须把每一个维度降到最小值，其他维度全范围，
        才是完整的 base case
        */
        for (int i = 0; i < sz; i++) {
            cash[i][0] = 0;
            stock[i][0] = -10000; // 不可能0次交易就能买入的
        }
        for (int j = 0; j <= k; j++) {
            cash[0][j] = 0;
            stock[0][j] = -prices[0];
        }
        for (int i = 1; i < sz; i++)
            for (int j = 1; j <= k; j++) {
                stock[i][j] = max ( stock[i-1][j], cash[i-1][j-1] - prices[i] );
                cash[i][j] = max ( cash[i-1][j], stock[i-1][j] + prices[i] );
            }
        return cash[sz-1][k];
    }
};