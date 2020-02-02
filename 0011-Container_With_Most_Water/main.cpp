#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int sz = height.size();
        int l = 0, r = sz - 1, res = 0;
        while (l < r) {
            res = max(res, min(height[l], height[r]) * (r - l));
            // 相向移动，从两边找最长的柱子
            // 这样不会漏解的原因是，面积变大，总得从宽*高，中往一个边长的方向发展
            // 上来宽就是max，那更大的面积，就只有在宽减少时，高度增加
            // 选高度高的index移动，高度低的index不动，这样就不会漏解
            if (height[l] < height[r])
                l++;
            else {
                r--;
            }
        }
        return res;
    }
};

int main() {
    vector<int> vec = { 1,8,6,2,5,4,8,3,7 };
    cout << Solution().maxArea(vec) << endl;
    return 0;
}
