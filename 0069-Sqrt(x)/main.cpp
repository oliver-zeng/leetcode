// leetcode 69. Sqrt(x)
class Solution {
public:
    int mySqrt(int x) {
        // 把不适用的 1 先抛去
        if (x == 1)
            return x;
        // right 不用从 x 开始，因为除去1开根后至少是一半的
        int left = 2, right = x/2;
        long long mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (mid * mid > x)
                right = mid - 1;
            else if (mid * mid < x)
                left = mid + 1;
            else
                return mid;
        }
        return right;
    }
};