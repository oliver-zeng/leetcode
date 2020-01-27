#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    bool g_debug = false;
    int sz;
    vector<bool> used;
    vector<int> tmp;
    vector<vector<int>> res;

    // index用于记录选取到第几个数了，直至选取到sz - 1个数结束
    // 每次选取的范围是nums[0. sz-1]中减去已选取过的数
    // 通过辅助数组used记录是否选取，避免每次都通过遍历来判断是否已经使用，效率太低
    void calcPermute(vector<int>& nums, int index) {
        if (g_debug) cout << "[" << index << "] enter" << endl;
        if (index > sz - 1) {
            res.push_back(tmp);
            if (g_debug) {
                cout << "[" << index << "] leaf return : tmp ";
                for (auto elm : tmp)
                    cout << elm << " ";
                cout << endl;
            }
        }

        // 在第index时，选择数字nums[i]
        for (int i = 0; i < sz; i++) {
            if (!used[i]) {
                if (g_debug)
                    cout << "[" << index << "] choose nums[" << i << "]" << endl;
                // 回溯到底后，若有需要的话，还需在递归结束，回溯完成后
                // 把之前压栈到p的相关变量退出来
                used[i] = true;
                tmp.push_back(nums[i]);
                calcPermute(nums, index + 1);
                tmp.pop_back();
                used[i] = false;
            }
        }

        if (g_debug)
            cout << "[" << index << "] return" << endl;
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sz = nums.size();
        tmp.clear();
        res.clear();
        used = vector<bool>(sz, false); // true used, false not used
        calcPermute(nums, 0);
        return res;
    }
};

int main() {
    vector<int> vec = {1,2,3};
    Solution().permute(vec);
    return 0;
}
