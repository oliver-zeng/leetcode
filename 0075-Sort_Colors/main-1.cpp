#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    bool g_debug = false;
public:
    void sortColors(vector<int>& nums) {
        // use nums
        int zero = -1;
        int two = nums.size();
        for (int i = 0; i < two;) {
            if (g_debug) {
                printVec(nums);
                cout << "process index [" << i << "] : " ;
            }
            if (nums[i] == 0) { // [0, zero] is 0
                swap(nums[++zero], nums[i]);
                i++;
            } else if (nums[i] == 2) { // [two, sz - 1] is 2
                swap(nums[i], nums[--two]);
            } else {  // nums[i] == 0, [zero + 1, i) is 1
                i++;
            }
            if (g_debug) printVec(nums);
        }
    }

    void printVec(vector<int>& vec) {
        for (auto elm : vec)
            cout << elm << " ";
        cout << endl;
    }
};

int main() {
    vector<int> vec = { 2,0,1 };
    Solution res = Solution();
    res.sortColors(vec);
    cout << "done : ";
    res.printVec(vec);

    return 0;
}
