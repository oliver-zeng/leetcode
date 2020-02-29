// ip地址共有4段，每段是范围在[0, 255]的数字
// 要求把给出的数字全用上，所以'010'转成10是不合题意的
class Solution {
private:
    vector<string> res;
    string str = "";
    void dfs (string &s, int step, int index) {
        if (step == 4) {
            if (index != s.size())
                return;
            res.push_back(str);
        }
        // 从index开始sz个数，区间是[index, index + sz)
        // 所以index + sz最多可以到s.size()
        for (int sz = 1; sz <= 3 && index + sz <= s.size(); sz++) {
            int num = stoi(s.substr(index, sz));
            // 0开头的通过stoi转出来都会去掉0
            // 所以只有'0'转换成0才是不丢位数，符合题意的
            if (s[index] == '0' && sz > 1)
                continue;

            if (num >= 0 && num <= 255) {
                string tmp = str;
                str+= to_string(num);
                if (step < 3)
                    str += ".";
                dfs (s, step + 1, index + sz);
                str = tmp;
            }
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        dfs (s, 0, 0);
        return res;
    }
};