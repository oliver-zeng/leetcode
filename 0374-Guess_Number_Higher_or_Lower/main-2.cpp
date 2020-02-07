// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        // 二分查找的边界是由查找范围决定的
        // 如果规定查找范围为[l, r)，那么结束条件就在l == r
        // 因为r是开区间，所以要比实际值大1
        // 因为出现了+1操作，就有发生溢出的可能，为了防止溢出将原数据强转成更大的存储类型
        long l = 1, r = (long)n+1;
        long mid = l + ((r - l) >> 1);
        while (l < r) {
            mid = l + ((r - l) >> 1);
            if (guess(mid) == 1)
                l = mid + 1; // 在[mid + 1, r)中继续查找
            else if (guess(mid) == -1)
                r = mid; // 在[l, mid)中继续查找，要包含mid - 1
            else {
                //assert (guess(mid) == 0);
                return mid;
            }
        }
        // 依题意绝不会走到，可以任意值
        // 这里返回[1, n]以外的，以示区分
        return 0;
    }
};
