class Solution {
private:
    vector<vector<int>> memo;
    int calcNums(int m, int n, vector<int>& nums) {
        if ( m > n ) return 0;
        if (memo[m][n] != -1) return memo[m][n];
        if ( n - m == 0 ) return nums[m];
        if ( n - m == 1 ) return max( nums[m], nums[n] );
        int res = 0;
        for (int i = m; i <= n - 2; i++)
            res = max( res, nums[i] + calcNums(i + 2, n, nums));
        res = max(res, nums[n-1]);
        res = max(res, nums[n]);
        return memo[m][n] = res;
    }
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if ( size == 0 ) return 0;
        if ( size == 1 ) return nums[0]; // nums.size() - 2
        if ( size == 2 ) return max(nums[0], nums[1]); // nums.size() - 2
        memo = vector<vector<int>>(size, vector<int>(size, -1));
        int res = nums[0] + calcNums(2, size - 2, nums);
        for (int i = 1; i <= nums.size() - 2; i++)
            res = max(res, nums[i] + calcNums(i + 2, size - 1, nums));
        return res;
    }
};
