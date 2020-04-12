class Solution {
public:
    int myAtoi(string str) {
        int sz = (int)str.size();
        int sign = 1;
        int i = 0;
        while (str[i] == ' ') i++;
        if (str[i] == '+') i++;
        else if (str[i] == '-') {
            sign = -1;
            i++;
        }
        // 当该去数字的时候，不是数字就是错误的，返回end
        if (!(str[i] >= '0') || !(str[i] <= '9'))
            return 0;
        long long res = 0;
        while (str[i] >= '0' && str[i] <= '9') {
            res = res*10 + str[i] - '0';
            // 后面跟INT_MIN去比也是最小值，是因为此时还没有添加符号位
            // 先把INT_MIN转成正数，当res超过正数-(long long)INT_MIN时
            // res加上负号就是更小的，此时应该要取INT_MIN
            res = sign == 1 ? min(res, (long long)INT_MAX) : min(res, -(long long)INT_MIN);
            i++;
        }
        // 数字部分过后，无论还有什么字符输入，都可以不看了，直接返回
        return sign * res;
    }
};