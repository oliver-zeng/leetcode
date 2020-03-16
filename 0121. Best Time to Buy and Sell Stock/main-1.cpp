class Solution {
public:
    // 遍历了所有买进卖出的可能
    // 每次固定买进点，然后找卖出的最大值
    // 等下次买进点向后移动时，之前卖出的最大值是有可能变得不可取的
    // 所以每次都需要重新找一次最值，复杂度是O(n^2)的
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        if (!sz)
            return 0;
        int res = INT_MIN;
        for (int i = 0; i < sz - 1; i++)
            for (int j = i + 1; j < sz; j++)
                res = max(prices[j] - prices[i], res);
        // 对于价值问题，什么都不做，也总比亏钱好
        if (res < 0)
            return 0;
        return res;
    }
};