#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    bool g_debug = false;
public:
    void sortColors(vector<int>& nums) {
        int s[3] = {0};
        //int s[3] = {0, 0, 0};
        for (int i = 0; i < nums.size(); i++) {
            s[nums[i]]++;
            if (g_debug) {
                cout << "[" << i << "] " << nums[i] << endl;
                for (int i = 0; i < 3; i++)
                    cout << "s[" << i << "]" << s[i] << endl;
            }
        }

        int j = 0;
        int index;
        for (int i = 0; i < sizeof(s)/sizeof(int); i++) {
            if (g_debug) cout << i << " : " << s[i] << endl;
            // j size need update to new index
            index = j + s[i];
            for (; j < index; j++) {
                if (g_debug) {
                    cout << "j " << j << endl;
                }

                nums[j] = i;
            }
        }
        return;
    }
    void printVec(vector<int>& nums) {
        for (auto elm : nums)
            cout << elm << " ";
        cout << endl;
    }

};

int main() {
    vector<int> nums = { 2,0,2,1,1,0 };
    Solution().sortColors(nums);
    Solution().printVec(nums);

    return 0;
}
