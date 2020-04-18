class Solution {
public:
    int hammingWeight(uint32_t n) {
        // n：        A + 1 + 0..0
        // n-1：      A + 0 + 1..1
        // n & (n-1)：A + 0 + 0..0
        int res = 0;
        while (n) {
            res++;
            n &= (n-1); 
        }
        return res;
    }
};