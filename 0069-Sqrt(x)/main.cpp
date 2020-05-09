class Solution {
public:
    int mySqrt(int x) {
        int left = 1, right = x;
        // 尽管mid是在[left, right]之间，但由于有mid*mid操作
        // 所以mid类型是left right类型的两倍
        long long mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (mid * mid < x)
                left = mid + 1;
            else if (mid * mid > x)
                right = mid - 1;
            else
                return mid;
        }
        // left是mid*mid < x，right是mid*mid > x
        // 所以当循环结束时，right是最后一个mid*mid < x
        return right;
    }
};