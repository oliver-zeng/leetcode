// 这题双指针的精髓是，向内收缩宽度一定是减少的，只有两边高度增加面积才有可能变大
class Solution {
public:
    // 盛水问题，看两个高度里最小的，只要不改变最小的，当宽度减少时就不可能增大
    // 因此每次向内移动短板，所有的消去状态都不会导致丢失面积最大值 。
    // 在每一个状态下，无论长板或短板收窄 1 格，都会导致水槽 底边宽度 −1：
    // 若向内移动短板，水槽的短板 min(h[i],h[j]) 可能变大，因此水槽面积 S(i,j) 可能增大。
    // 若向内移动长板，水槽的短板 min(h[i],h[j]) 不变或变小，下个水槽的面积一定小于当前水槽面积。
    int maxArea(vector<int>& height) {
        int sz = (int) height.size();
        int i = 0, j = sz-1;
        int res = 0;
        while (i < j) {
            // 在一上来while判断完i<j时，就算res
            // 就不会出现改变i & j后越界的情况了
            res = max(res, min(height[i], height[j]) * (j - i));
            // 并且在height[i] == height[j]时，任意改变一个就可以做到不漏解了
            // 但实际上是可以两边同时变化的，因为高度只会小于等于这个相等的值，宽度再减少，面积一定是减少的
            if (height[i] > height[j]) {
                j--;
            } else if (height[i] < height[j]) {
                i++;
            } else {
                i++;
                j--;
            }
        }
        return res;
    }
};