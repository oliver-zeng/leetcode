class Solution {
private:
    vector<string> res;
    vector<int> tmp;
    string getNum(vector<int> tmp) {
        int hour = tmp[9] * 8 + tmp[8] * 4 + tmp[7] * 2 + tmp[6];
        if (hour > 11)
            // ""是空string，NULL是空指针
            return "";
        int minute = tmp[5] * 32 + tmp[4] * 16 + tmp[3] * 8 + tmp[2] * 4 + tmp[1] * 2 + tmp[0];
        if (minute > 59)
            return "";
        if (minute < 10)
            return to_string(hour) + ":0" + to_string(minute);
        else
            return to_string(hour) + ":" + to_string(minute);
    }
    void dfs (int num, int step, int index) {
        if (num == step) {
            string s = getNum(tmp);
            // 判断空string的方法有
            // 1) s.empty() == true
            // 2) s.size() == 0
            // 3) s == ""
            if (s != "") res.push_back(s);
            return;
        }
        for (int i = index; i < 10; i++) {
            // step = 0 还没走到第一个dfs，代表一个还没取
            // num是总的要取个数，num - step 就是还要取的个数
            // [i 10) 是能取的区间，区间不够取了直接返回
            if (10 - i < num - step)
                break;
            tmp[i] = 1;
            dfs (num, step + 1, i + 1);
            tmp[i] = 0;
        }
    }
public:
    vector<string> readBinaryWatch(int num) {
        tmp = vector<int>(10, 0);
        dfs (num, 0, 0);
        return res;
    }
};