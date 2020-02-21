class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 在容器中找两个不相同的数，时间复杂度是O(n^2)
        // 但若找的这两个元素间，满足一定关系，且这个关系可以用键值对中的key来表示
        // 那就可以用查找表以O(n)的时间复杂度来实现
        // record：key是nums中元素值，value是key中值对应在nums中的index
        unordered_map<int, int> record;
        for (int i = 0; i < nums.size(); i++) {
            // 若可以找到满足target - num[i]关系的key
            // 无需第二次遍历就可以把记录的key对应index找到
            if (record.find(target - nums[i]) != record.end())
                return {i, record[target - nums[i]]};
            record[nums[i]] = i;
        }
        // 函数在结束位置必须有返回值，若没有可以return任意值，或用throw抛出异常
        throw invalid_argument("input no solution");
    }
};
