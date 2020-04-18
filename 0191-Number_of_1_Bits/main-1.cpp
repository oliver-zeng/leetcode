class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        int mask = 1;
        int count = 32;
        // 右移高位补1，而左移低位补0
        // 所以只能是去左移掩码，不能右移要数的n
        while (--count) {
            if (n & mask)
                res++;
            mask <<= 1;
        }
        // 注意最后一次mask到最高位后，没有进入循环，所以还少判了一次
        // 说白了就是，因为mask初始为1，mask只需左移31次，但n共32bits要判断n&mask32次
        if (n & mask) res++;
        return res;
    }
};