class Solution {
public:
    // 固定卖出点，这题实际上，是在找所有点，与该点前最小值的最大差值
    // 最小值是不断添加的过程，所以可以记录最小值不断更新
    // 不需要每次都重新遍历最小值，复杂度为O(n)
    // 不同于上一个复杂度为O(n^2)的解法
    // 由于处于删除过程，所以每次最值都要重新计算
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        if (!sz)
            return 0;
        int minPrice = prices[0], res = INT_MIN;
        for (int i = 1; i < sz; i++) {
            minPrice = min(prices[i], minPrice);
            res = max(prices[i] - minPrice, res);
        }
        // 对于价值问题，什么都不做，也总比亏钱好
        if (res < 0)
            return 0;
        return res;
    }
};