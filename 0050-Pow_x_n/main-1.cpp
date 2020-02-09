// 求m^n，如果按照m*m*...*m用n个m相乘的话时间复杂度为O(n)，会超时
// 所以阶乘的n要从O(n)进一步优化到O(log n)才行，方法是
// 当n为偶数时，m^n = m^(n/2) * m^(n/2)
// 当n为奇数时，m^n = m * m^(n/2) * m^(n/2)
// 然后不断对n/2判断奇偶递归求解
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1.0;
        // n若为负数，先转换为正数，再按奇偶性继续求解
        // 这里在负数最大值时，无法使用abs，会越界
        // egation of -2147483648 cannot be represented in type 'int'
        // 所以不能负数转正再算，必须直接把负数拆两半算，这样n才能不越界
        //if (n < 0)
            //return 1/myPow(x, abs(n));

        // 避免myPow(x, n>>1)重复计算，先提前算出来
        // double t = myPow(x, n>>1); 写成这样就会有bug
        double t = myPow(x, n/2);
        // 这里必须用%判断奇偶，n & 1不能用于n为负数时
        if (n % 2 == 0) // 无论正负偶数阶，拆成两半，刚刚好
            return t * t;
        else if (n > 0) // 奇数的正数阶，拆成两半，还要再乘一个
            return t * t * x;
        else // 奇数的负数阶，拆成两半，还要多除一个
            return t * t / x;
    }
};
