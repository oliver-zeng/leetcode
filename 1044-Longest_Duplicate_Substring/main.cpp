class Solution {
public:
    string longestDupSubstring(string S) {
        unordered_set<unsigned int> dict;
        unsigned int sz = S.size();
        unsigned int left = 1, right = sz;
        string res = "";
        while (left <= right) {
            unsigned int len = left + (right - left) / 2;
            unsigned int sum = 0;
            bool find = false;
            // 在每轮比较时，必须要确保字符的长度相等
            // 否则"nan"与"anan"因为在最高位的'a'值为0，会导致二者编码相等
            // 因此每个长度在比较时，要把dict清空，以相同长度的编码字典来查找
            dict.clear();
            // 最高位是len-1次幂，是从长度为1对应着的0次幂开始的
            // 当len较大时，对26做的连续乘法会溢出，int无法存下
            // 至于第几次乘法会溢出不用关心，至少在26*26是不会溢出的
            // 所以每次乘完，都取模就行了，int就用2^32
            //int r = pow(26, len-1);
            unsigned int r = 1;
            for (int i = 0; i < len - 1; i++)
                r = (r * 26) % UINT_MAX;
            for (int i = 0; i < len; i++) {
                // 这里转换成的26进制数，将字符用0-25来对应
                // 必须是一一对应的才可以，否则算出的来的数字将不是唯一的
                //sum = sum *26 % UINT_MAX;
                //sum += S[i] - 'a';
                sum = (sum * 26  + S[i] - 'a') % UINT_MAX;
            }
            dict.insert(sum);
            for (int i = 1; i + len <= sz; i++) {
                sum -= ((S[i-1] - 'a') * r) % UINT_MAX;
                sum = (sum * 26 + (S[i + len - 1] - 'a')) % UINT_MAX;
                // 二分每次更新都是最近接的正解，所以二分退出时，就是要找的正解了
                if (dict.count(sum)) {
                    res = S.substr(i, len);
                    find = true;
                    break;
                }
                dict.insert(sum);
            }
            if (find) {
                left = len + 1;
            } else {
                right = len-1;
            }
        }
        return res;
    }
};