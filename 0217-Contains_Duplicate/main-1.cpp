class Solution {
private:
    // 只要改动一下存储的数据结构就可以大幅提高效率
    // 不需要有序的话，当然是无序所有表操作都是O(1)的查找表效率高
    //set<int> used;
    unordered_set<int> used;
public:
    bool containsDuplicate(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 0)
            return false;
        for (auto elm : nums) {
            if (used.find(elm) != used.end())
                return true;
            else
                used.insert(elm);
        }
        return false;
    }
};
