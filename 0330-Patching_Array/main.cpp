class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        // [1, upper) 表示当前可表示连续数的范围
        // 若想增加upper，需要的数字可以为<=upper的任意数字
        // 但若数字>upper则肯定无法在[1, upper)基础上增加upper
        // 此时就需要先提高原有连续数字的范围，增加upper是提高连续数字最多的
        // [1, upper) + [1+upper, upper + upper) + [upper] = [1, upper+upper)
        long long upper = 1, res = 0, i = 0;
        // 当 upper超过n时，[1, upper) 才是满足题意的连续区间
        while (upper <= n) {
            // 有数的时候，若数能用，直接用这个数
            if (i < nums.size() && nums[i] <= upper) {
                upper += nums[i];
                i++;
            } else { // 没数，或数不能用，就要上patch upper
                upper += upper; // 有加法就要防止溢出，由int改为long long
                res++;
            }
        }
        return res;
    }
};