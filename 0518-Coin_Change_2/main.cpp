class Solution {
public:
    // 完全背包模板
    // 通过选择凑容量
    // 选择在外层循环，容量在内层循环 => 组合数（518. 零钱兑换 II）
    // 容量在外层循环，选择在内层循环 => 排列数（70.爬楼梯）
    #if 0
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        // 排列数（70.爬楼梯）
        // 不规定币值顺序，任意出现顺序的币值均可插在前面凑得序列的后面
        // 每种币值出现的顺序是不确定的
        // 比如 [1] 凑出dp[1]，[1, 1] 与 [2] 凑出dp[2]
        // 当需要凑dp[3]时，1插在基于dp[2]得到序列[2]的后面，得到[2, 1]
        // 2插在基于dp[1]得到序列[1]的后面，得到[1,2]
        for (int j = 1; j <= amount; j++) // 只能取第i种货币
            for (int i = 0; i < coins.size(); i++)
                if (coins[i] <= j) {
                    dp[j] += dp[j-coins[i]];
                }
        return dp[amount];
    }
    #else
    int change(int target, vector<int>& c) {
        vector<int> dp(target+1);
        dp[0] = 1;
        // 组合数（518. 零钱兑换 II）
        // 组合问题需要规定好书写顺序，不允许在后面的硬币层次使用之前的硬币。 
        // 相当于是限定了填的顺序，后面出现的币值只会填在前面出现币值的后面
        // 比如 [1, 2, 1] [2, 1, 1] [1, 2, 2] 只会出现一种顺序 [1, 2, 2]
        for(int i = 1; i <= c.size(); i++){ // 依次选前i种硬币
            for(int j = c[i-1]; j <= target; j++){
                dp[j] += dp[j-c[i-1]];
            }
        }
        return dp[target];
    }
    #endif
};