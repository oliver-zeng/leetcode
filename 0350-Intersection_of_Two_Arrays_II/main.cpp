class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        map<int, int> record;
        // c++不用判断key是否存在，就可以直接以初值0来访问，统计key出现的个数
        for (auto elm : nums1)
            record[elm]++;
        for (auto elm : nums2)
            // 同理这里也不用先判断 record.find(elm) != record.end()
            // 就可以直接判断record[elm]的值，若key不存在里面读到的将会是0
            // 在c++中访问不存在key，就相当于是执行map[key] = 0的操作
            if (record[elm]!=0) {
                res.push_back(elm);
                record[elm]--;
            }
        return res;
    }
};
