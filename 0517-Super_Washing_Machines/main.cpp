class Solution {
public:
    // 这题思路的关键是：
    // 只需要考虑一边，这里只考虑多的，少的是被动接收的
    // 因此就是看多的最少多少次，能送平均
    // 并且因为可以在多个洗衣机间同时移动
    // 所以达到平均数的洗衣机，就相当于是不存在，只作为传递使用了
    // 因此只需要考虑每个洗衣机，往两边送的最多的数量，就是最少移动次数
    int findMinMoves(vector<int>& machines) {
        int sum = 0;
        int sz = machines.size();
        for (int elm : machines)
            sum += elm;
        if (sum % sz) return -1;
        int avg = sum / sz, left = 0, right, res = 0;
        int remain_left, remain_right;
        for (int i = 0; i < sz; i++) {
            right = sum - left - machines[i];
            remain_left = left - i * avg;
            remain_right = right - (sz - i - 1) * avg;
            int tmp = 0;
            if (remain_left < 0)
                tmp -= remain_left;
            if (remain_right < 0)
                tmp -= remain_right;
            res = max(res, tmp);
            left += machines[i];
        }
        return res;
    }
};