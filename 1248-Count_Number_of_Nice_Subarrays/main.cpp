class Solution {
    // dp选择的分割，只能考虑分成两段，区间[0, i-1] + [i, n]的关系
    // 无法解决 [0, i-1] + [i, j] + [j+1, n] 三段间的关系
    // 而三段保持中间段[i, j]与旁边两段的技巧就是用「滑块」或「queue」
    // 保持拥有k个奇数的滑块[i, j]，其中nums[i]与nums[j]分为奇数
    // 包含这个滑块里k个奇数的子数组的，起始范围是(i前一个奇数, 奇数i]，终止范围是[奇数j，j后一个奇数)
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int res = 0;
        unsigned int sz = nums.size();
        int left = 0, right = 0, count = 0;
        // left找到第一个奇数
        while (left < sz && (nums[left] % 2 == 0)) left++;
        // right找到第k个奇数
        right = left + 1;
        while (--k && right < sz) {
            while (right < sz && (nums[right] % 2 == 0)) right++;
            // 这里因为会停在第一个不满足的地方，所以要找第k-1个不满足的地方
            // 每次都需要，把找到的不满足的地方，往后挪一下，这样才能去找下一个
            right++;
        }
        // 把最后多挪的一个减回去，就刚好是第k个不满足的点
        right--;
        // 如果压根就不存在k个奇数，那就直接退出了
        if (k != 0)
            return 0;

        // 子串起点的范围是(上一个奇数，这一次的奇数]
        // 终点范围是[本次奇数，到下一次奇数)
        // (lastLeft, left] * [right, lastRight)
        int lastLeft = -1;
        while (right < sz) {
            int nextRight = right+1;
            while (nextRight < sz && (nums[nextRight] % 2 == 0)) nextRight++;
            res += (left - lastLeft) * (nextRight - right);
            right = nextRight;
            lastLeft = left;
            left++;
            while (left < sz && (nums[left] % 2 == 0)) left++;
        }
        return res;
    }
};