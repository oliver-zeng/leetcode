#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    bool g_debug = true;
public:
    int removeDuplicates(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) return 0;
        // 单向只要保证，i已经在k的里面了，且k的增长不会超过i
        // 那么i前面的部分，就相当于是extra buffer了，而且因为是原地的，不需要额外拷贝
        int k = 0;
        bool more_than_one = false;
        for (int i = 1; i < sz; i++) {
            if (nums[i - 1] == nums[i])
                more_than_one = true;
            if (nums[i] != nums[k]) {
                if (more_than_one && ( k <= sz - 2 )) {
                    nums[k+1] = nums[k];
                    k++;
                    more_than_one = false;
                }
                nums[++k] = nums[i];
            }
        }
        // more_than_one在最后没有nums[i] != nums[k]时，会少处理一次
        // 所以在循环结束时补上，最后一次的more_than_one处理
        if (more_than_one) {
            nums[k+1] = nums[k];
            k++;
        }
        return k + 1;
    }
};

int main() {

    //vector<int> vec = { 1,1,1,2,2,3 };
    vector<int> vec = { 0,0,1,1,1,1,2,3,3 };

    Solution().removeDuplicates(vec);
    for (auto elm : vec)
        cout << elm << " ";
    cout << endl;

    return 0;
}
