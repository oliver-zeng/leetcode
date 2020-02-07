// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        // 二分查找的边界是由查找范围决定的
        // 如果规定查找范围为[l, r]，那么结束条件就是在l > r
        int l = 1, r = n;
        int mid = l + ((r - l) >> 1);
        while (l <= r) {
            mid = l + ((r - l) >> 1);
            if (guess(mid) == 1)
                l = mid + 1; // 在[mid + 1, r]中继续查找
            else if (guess(mid) == -1)
                r = mid - 1; // 在[l, mid - 1]中继续查找
            else
                return mid;
        }
        // 依题意绝不会走到，可以任意值
        // 这里返回[1, n]以外的，以示区分
        return 0;
    }
};
