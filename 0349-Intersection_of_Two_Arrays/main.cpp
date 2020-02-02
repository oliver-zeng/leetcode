class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> record;
        set<int> res;
        // 往set里插入元素，相同元素只会出现一次，不用担心有多个
        for (auto elm : nums1)
            record.insert(elm);
        for (auto elm : nums2)
            if (record.find(elm) != record.end())
                // 所以根本不需要，额外判断元素是否在容器中已经有了
                // 放心insert就是了，相同元素只会存进去一个
                res.insert(elm);
        return vector<int>(res.begin(), res.end());
    }
};
