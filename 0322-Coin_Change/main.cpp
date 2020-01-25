class Solution {
private:
    vector<int> memo;
    int min_coin = INT_MAX;
    int calcChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (amount < min_coin) return -1;
        if (memo[amount] != 0) return memo[amount];
        int result = INT_MAX;
        for (int i = coins.size() - 1; i >= 0; i--)
            if (calcChange(coins, amount - coins[i]) != -1)
                result = min(result, calcChange(coins, amount - coins[i]) + 1);
        memo[amount] = (result == INT_MAX ? -1 : result);
        return memo[amount];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        for (int i = 0; i < coins.size(); i++)
            min_coin = min(min_coin, coins[i]);
            
        memo = vector<int>(amount + 1, 0);
        return calcChange(coins, amount);
    }
};
