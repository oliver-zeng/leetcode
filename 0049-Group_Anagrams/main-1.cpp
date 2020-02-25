class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 为字符串设key的方法
        unordered_map<string, vector<string>> freq;
        // 循环成员是非基本类型时
        // 用&可以减少拷贝构造提高性能
        // auto是变量类型，关键字添加在auto上
        //for (auto str : strs) {
        //for(const string& str : strs) {
        for (const auto& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            freq[key].push_back(str);
        }

        vector<vector<string>> res;
        vector<string> vec;
        /*
        for (auto elm : freq) {
            vec.clear();
            for (auto str : elm.second) {
                cout << str << ", ";
                vec.push_back(str);
            }
            res.push_back(vec);
        }
        */

        // freq里value就是vector了
        // 直接把vector添加进去即可
        // 上面拆开再合上，纯属画蛇添足
        for (const auto& p : freq)
            res.push_back(p.second);

        return res;
    }
};