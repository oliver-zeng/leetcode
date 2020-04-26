class Solution {
public:
    bool isPalindrome(int x) {
        // 负数没有回文数
        if (x < 0)
            return false;
        // int类型的计算结果，要用long long来存储，才能避免overflow
        long long reverse = 0;
        int num = x;
        while (num) {
            reverse = reverse * 10 + (num % 10);
            num /= 10;
        }
        if ((int)reverse == x)
            return true;
        return false;
    }
};