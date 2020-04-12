class Automaton {
    // 状态机
    // 一共四种状态 start signed in_number end
    // 建立状态表 map[from][to]，以及起始from的状态
    // map[key]中key对应的是vector，vector中成员是map[key][get_col(c)]
    string state = "start";
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };
    // from状态在各种输入下对应的to状态
    // 输入分为四种类型 空字符、正负号、数字、其他
    int get_col(char c) {
        if (isspace(c)) return 0;
        if (c == '+' or c == '-') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }
public:
    int sign = 1;
    // 返回值是int类型，为防止计算过程中越界定义为long long类型
    long long ans = 0;

    void get(char c) {
        // 根据输入进行from到to状态转换
        state = table[state][get_col(c)];
        // 处理当前状态下的数据
        if (state == "in_number") {
            ans = ans * 10 + c - '0';
            // 当ans超过(long long)INT_MAX或-(long long)INT_MINT时，取最小值
            // 这里INT_MAX与INT_MIN是int类型，所以要强转成long long
            // 后面跟INT_MIN去比也是最小值，是因为此时还没有添加符号位
            // 先把INT_MIN转成正数，当res超过正数-(long long)INT_MIN时
            // res加上负号就是更小的，此时应该要取INT_MIN
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if (state == "signed")
            sign = c == '+' ? 1 : -1;
    }
};

class Solution {
public:
    int myAtoi(string str) {
        Automaton automaton;
        for (char c : str)
            automaton.get(c);
        // 正负符号的表示法是 1或-1 乘以 ans
        return automaton.sign * automaton.ans;
    }
};