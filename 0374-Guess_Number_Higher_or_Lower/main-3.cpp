/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int len = n, left = 1;
        // 在做链表的二分查找时，就没有靠right就找不到mid
        // 只能用一半的长度len，与left来找mid
        while (len > 0) {
            // 注意一定要用step来接收一半长度的len来计算步长
            // 不能用mid，因为mid = left + step，left是会变的
            int step = len / 2;
            // [left, left + len]是len+1个数字
            int mid = left + step;
            if (guess(mid) == -1)
            	len = step;
            else if (guess(mid) == 1) {
                left = mid + 1;
                len -= step + 1;
            } else
            	return mid;
        }
        return -1;
    }
};