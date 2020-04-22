#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0) return 0;
        int l = 0, r = -1, sum = 0, res = INT_MAX;
        while (l < sz) {
            if ((r + 1 < sz) && (sum < s))
                sum += nums[++r];
            else {
                if (sum >= s)
                    res = min(res, r - l + 1);
                sum -= nums[l++];
            }

        }
        if (res == INT_MAX) return 0;
        return res;
    }
};

int main() {
    vector<int> nums = { 2,3,1,2,4,3 };
    cout << Solution().minSubArrayLen(7, nums) << endl;
    return 0;
}
