#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int sz = nums.size();
        // get first 0, it is writable pos
        int writable_pos;
        for (writable_pos = 0; writable_pos < sz; writable_pos++)
            if (nums[writable_pos] == 0)
                break;
        // overwrite writable_pos
        for (int i = writable_pos + 1; i < sz; i++)
            if (nums[i])
                nums[writable_pos++] = nums[i];
        // add 0
        for (int i = writable_pos; i < sz; i++)
            nums[i] = 0;
    }
};

int main() {
    vector<int> vec = { 0,1,0,3,12 };
    Solution().moveZeroes(vec);
    for (auto elm : vec)
        cout << elm << ", ";
    cout << endl;
    return 0;
}
