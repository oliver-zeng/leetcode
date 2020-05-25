class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // 摩尔投票，一开始累积为0时，可以初始值为任意值
        vector<int> candicate(2, -1);
        vector<int> count(2, 0);
        // 摩尔投票，找出最多的candicate
        for (auto elm : nums) {
            bool diff = true;
            for (int i = 0; i < candicate.size(); i++) {
                if (candicate[i] == elm) {
                    count[i]++;
                    diff = false;
                    break;
                }
            }
            // elm是非最多的，就要一同减
            if (diff) {
                bool change = false;
                // 若有换出最多的，那换掉的就不是最多的
                // 此时就不能同时减1了，因为此时剩下的都是最多的，不能只有最多间抵消，非最多没有抵消
                for (int i = 0; i < candicate.size(); i++) {
                    if (count[i] == 0) {
                        candicate[i] = elm;
                        count[i] = 1;
                        change = true;
                        break;
                    }
                }
                if (!change) {
                    for (int i = 0; i < candicate.size(); i++) {
                        count[i]--;
                    }
                }
            }
        }
        // 统计最多的candicate是否超过要求的占比
        vector<int> res;
        count = vector<int>(2, 0);
        for (auto elm : nums)
            for (int i = 0; i < candicate.size(); i++)
                if (candicate[i] == elm)
                    count[i]++;
        for (int i = 0; i < candicate.size(); i++)
            if (count[i] > nums.size()/3)
                res.push_back(candicate[i]);
        return res;
    }
};