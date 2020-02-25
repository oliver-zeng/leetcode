class Solution {
private:
    // 以为实参已经定义成const类型了，所以形参必须也是const才能接收
    // 否则会认为在函数里这个实参是可以改变的，造成编译错误
    //string getKey(string &str) {
    string getKey(const string &str) {
        // 统计纯字母字符串的数据可以用数组index
        vector<int> record(26, 0);
        for (auto c : str)
            record[c - 'a']++;
        string key = "";
        // auto尽量少用，非常容易迷失，不知道成员是什么了
        for (auto i : record)
            // 记得每个数据用"#"隔开，否则会乱掉
            key += to_string(i) + "#";
        return key;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> freq;
        // 循环成员是非基本类型时
        // 用&可以减少拷贝构造提高性能
        // auto是变量类型，关键字添加在auto上
        //for (auto str : strs) {
        //for(const string& str : strs) {
        for (const auto& str : strs) {
            string key = getKey(str);
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