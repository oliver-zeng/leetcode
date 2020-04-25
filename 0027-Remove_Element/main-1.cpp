#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int sz = nums.size();
        int i = 0, j = sz - 1;
        // 一定要注意，初始值定义在循环体外时，循环体就不要再定义初始值了
        // for (int i = 0; ...) 这里多个i，特别容易看漏，不好查错
        for (i = 0; i < sz; i++) {
            if (nums[i] == val) {
                // i有循环保证不越界，j没有要自行保证j--不越界
                // 找到最后面可供交换的非val值位置为j
                while ((nums[j] == val) && (j > 0))
                    j--;
                // 若i = j，因为i已经是等于val的值了
                // j能等于i说明是后面没有了，直接结束
                if (i < j)
                    swap(nums[i], nums[j]);
                else
                    break;
            }
        }
        // 循环结束时i是第一个等于val的下标，前面非val[0, i - 1]共有i个数
        return i;
    }
};

int main() {
    vector<int> vec = { 3,2,2,3 };

    Solution().removeElement(vec, 3);
    for (auto elm : vec)
        cout << elm << " ";
    cout << endl;
    return 0;
}
