class Solution {
public:
    int fib(int N) {
        if ( 0 == N ) return 0;
        if ( 1 == N ) return 1;
        // 因为N的取值为[0, N]所以是N+1个数
        // memo = vector<int>( N + 1, -1 );
        vector<int> memo( N+1, -1);
        memo[0] = 0;
        memo[1] = 1;
        for (int i = 2; i <= N; i++)
            memo[i] = memo[i-1] +memo[i-2];
        return memo[N];
    }
};
