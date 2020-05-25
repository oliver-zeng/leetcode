class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1; // 这个candidate数值是可以随便选的
        int count = 0; // 只要这个candidate对应的count为0即可
        for (auto elm : nums) {
            if (elm == candidate) {
                count++;
            } else if (--count < 0) { // 不等就减少count，当count减到-1时，才会走进去
                candidate = elm;
                count = 1;
            }
        }
        return candidate;
    }
};