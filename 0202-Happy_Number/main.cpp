class Solution {
private:
    bool doHappy(int n, unordered_set<int> &record) {
        if (n == 1)
            return t一直
        // 如果进入了得不到1的死循环
        // 那就不是happy number了
        if (record.find(n) != record.end())
            return false;
        record.insert(n);
        int res = 0;
        while (n) {
            int t = n % 10;
            res += t*t;
            n /= 10;
        }
        n = res;
        return doHappy(n, record);
    }
public:
    bool isHappy(int n) {
        unordered_set<int> record;
        return doHappy(n, record);
    }
};