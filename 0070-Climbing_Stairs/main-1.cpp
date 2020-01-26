class Solution {
private:
	vector<int> memo;
    int calcClimb(int n, vector<int> &memo) {
        // f(n) = f(n-1) + f(n-2)
        // mini positive integer is 1
        // n - 2 = 1 => n = 3
        // need initialize f(2) & f(1)
        if ( 1 == n ) return 1;
        if ( 2 == n ) return 2;
        if ( 0 == memo[n] )
        	memo[n] = calcClimb(n-1, memo) + calcClimb(n-2, memo);
        return memo[n];
    }
public:
    int climbStairs(int n) {
        memo = vector<int>(n + 1, 0);
        return calcClimb(n, memo);
    }
};
