class Solution {
public:
    int countPrimes(int n) {
        // less than a non-negative number n，范围是[2, n-1]
        vector<int> isPrime(n, true);
        // 素数Prime定义：只能被 1 和它本身整除的数
        // 实做的时候，不用从1一直试到n，只需要从 1 试到 sqrt(n)
        // 因为乘法交换律，后面出现的 4 * 2 已经在 2 * 4 试过了
        // i * i < n 等价于 i < sqrt(n)
        for (int i = 2; i * i < n; i++) {
            if (!isPrime[i])
                continue;
            // 自底向上，通过计算所有比n小质数的倍数，来得到所有n以下非素数的值
            // 这里j的起始值，从 2*i 优化为 i*i，来算所有素数的倍数
            // 是因为[2*i, i&i)这部分素数的倍数，已经在平方之前的质数计算中算过了
            // 素数 2 * {2, 3, 4, ..} 在倍数里面包含了所有素数
            // 所以后面素数倍数再算的时候，没必要再从比素数小的倍数开始，直接从第素数倍开始即可
            // 如 i=2是 4，6,8,10,12,14,16.... i=3 是 9,12,15
            // 那如果是 2*i, 那么 3 是 6,9，12,15 其实6是不用计算的，因为i=2 的时候已经计算过了
            for (int j = i * i; j < n; j += i)
                isPrime[j] = false;
        }
        int res = 0;
        for (int i = 2; i < n; i++)
            if (isPrime[i])
                res++;
        return res;
    }
};