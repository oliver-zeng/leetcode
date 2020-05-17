class Solution {
public:
    // 此题不能用滑动窗口
    // 因为nums里没说都是正整数，窗口[left, right]
    // 没法确保在right到达某一点，之后所有点都不能满足，只能移动left
    int subarraySum(vector<int>& nums, int k) {
        // dp记录的是子问题的答案，由子问题递推推得原问题答案
        // 这里无法通过子问题答案推原问题答案
        // 但可以记录子问题规模dp[i]为“从[0, i]的和”
        // 这样“[j,i]和”变为“dp[i] - dp[j-1]”从而推得原问题答案
        int sz = nums.size();
        if (sz == 0) return 0;
#ifdef TimeOut // O(n^2)会超时
        vector<int> dp(sz+1, 0);
        for (int i = 1; i <= sz; i++)
            dp[i] = dp[i-1] + nums[i-1];
        int res = 0;
        for (int i = 1; i <= sz; i++)
            for (int j = 1; j <= i; j++)
                if (dp[i] - dp[j-1] == k)
                    res++;
#else // O(n)使用unordered_map去查找[0,i]间j的所有可能
      // 这个才是真正的dp解法，unordered_map里记录的是和为x的所有可能
        unordered_map<int, int> dict;
        // 一开始和为0的就是一种可能，这样nums=[1,1] k=2才有解
        dict[0] = 1;
        int sum = 0, res = 0;
        for (int i = 0; i < sz; i++) {
            sum += nums[i];
            // 必须放在下面，不能包括dp[i]本身
            // 否则找dp[i] - dp[j-1]相当于找出的[j, i]是空了
            //dict[sum]++;
            if (dict.count(sum - k))
                res += dict[sum - k];
            dict[sum]++;
        }
#endif
        return res;
    }
};