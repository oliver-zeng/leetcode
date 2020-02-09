// 对n的O(log n)优化，不一定非要用递归对半
// 还有一种思路是，把n转换为二进制数
// 将二进制中每一位对应的m^2^x都算出来，这样只需要O(log n)
class Solution {
public:
    double myPow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        // 这里对n<0分两种情形：
        // 当n是负数最值时，就是正数最值再+1，所以多除一个x
        // 还一种是一般负数，将n转换为abs(n)即可
         if(n<0)
		{
			if(n==INT_MIN)
				return 1.0 / (myPow(x,INT_MAX)*x);
			else
				return 1.0 / myPow(x,-n);
		}
        if(n==0)
            return 1.0;
		double ans = 1.0 ;
		for(;n>0; x *= x, n>>=1)
		{
			if(n&1>0)
				ans *= x;
		}
		return ans;
    }
};
