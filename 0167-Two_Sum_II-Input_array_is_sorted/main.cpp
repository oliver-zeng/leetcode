#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    bool g_debug = true;
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int sz = numbers.size();
        int i = 0, j = sz - 1;
        while (i < j) {
            if (g_debug) {
                cout << "numbers[" << i << "] " << numbers[i] << endl;
                cout << "numbers[" << j << "] " << numbers[j] << endl;
            }
            if (numbers[i] + numbers[j] > target)
                j--;
            else if (numbers[i] + numbers[j] < target)
                i++;
            else // numbers[i] + numbers[j] == target
                break;
        }
        res.push_back(i+1);
        res.push_back(j+1);
        return res;
    }
};

int main() {
    vector<int> numbers = { 2,3,4 };
    vector<int> vec;
    vec = Solution().twoSum(numbers, 6);
    for (auto elm : vec)
        cout << elm << " ";
    cout << endl;
    return 0;
}
