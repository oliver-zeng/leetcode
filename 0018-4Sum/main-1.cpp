class Solution {
private:
    int nextNum(vector<int> &nums, int index) {
        int val = nums[index];
        for (int i = index + 1; i < nums.size(); i++)
            if (nums[i] != val)
                return i;
        // 这里返回大于[0, nums.size())的值
        // 就可以不再进入循环了
        return nums.size();
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int sz = nums.size();
        sort(nums.begin(), nums.end());
        // 等于key的组合可能不止一个
        // 在unordered_map里把value设为vector相当于unordered_multimap
        // 并且克服了unordered_multimap迭代顺序不稳定的弊端
        unordered_map<int, vector<pair<int, int>>> record;
        // 为避免重复要按元素顺序建表&查找：
        // 先对原序列排序，在遍历时，只遍历与当前元素值不同的
        // 在多重遍历里，后一重循环是从前一层循环的后一个开始
        // 那么如果有重复，自然也会不会落下了
        // 这样把满足key的值，按在pair里first <= second的顺序从小到大记下来
        for (int i = 0; i < sz; i = nextNum(nums, i))
            for (int j = i + 1; j < sz; j = nextNum(nums, j))
                record[nums[i] + nums[j]].push_back(make_pair(nums[i], nums[j]));

        vector<vector<int>> res;
        // 要确保i j后面还能有查找表里的两个数
        // 否则后面在找make_pair(nums[j+1], nums[j+1])时会越界
        // 所以i最多到 n - 4后面只剩3，j最多到n-3后面剩2
        for (int i = 0; i < sz - 3; i = nextNum(nums, i))
            for (int j = i + 1; j < sz - 2; j = nextNum(nums, j)) {
                // 在这里提前结束，可以加快速度，去掉不影响正确性
                if (nums[i] + nums[j] + nums[j+1] + nums[j+2] > target)
                    continue;
                // 在两层循环里找到前两个数，再从表里找符合的后两个数，位置要位于前两个数的后面
                // 后两个数在pair里是按first位置在second前的方式存放的
                // 与pair比较大小方式相同，先比first，若相等再比second
                // 所以可直接用lower_bound找到首个>=这pair的位置
                int key = target - nums[i] - nums[j];
                if (record.find(key) == record.end())
                    continue;
                auto it = lower_bound(record[key].begin(), record[key].end(), make_pair(nums[j+1], nums[j+2]));
                    for (; it != record[key].end(); it++)
                        res.push_back(vector<int>({nums[i], nums[j], it->first, it->second}));
            }
        return res;
    }
};
