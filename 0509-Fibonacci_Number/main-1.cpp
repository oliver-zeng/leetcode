class Solution {
private:
    vector<int> memo;
    int calcFib(int N, vector<int> &memo) {
        if ( N == 0 ) return 0;
        if ( N == 1 ) return 1;
        // 记忆化搜索的表记录的是需要重复计算的，
        // 赋初值的本来就不用算就不需要填表了
        if ( -1 == memo[N] )
        	memo[N] = calcFib( N - 1, memo ) + calcFib( N - 2, memo );
        return memo[N];
    }
public:
    int fib(int N) {
        // memo用匿名vector赋值
        // 因为N的取值为[0, N]所以是N+1个数
        memo = vector<int>( N + 1, -1 );
        return calcFib( N, memo );
    }
};
