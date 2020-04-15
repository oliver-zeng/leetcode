class Solution {
public:
    // 环状替换，把固定位置i替换到位置k，再把位置k继续替换，直至形成环
    // 此时再从i+1的位置开始替换，依次类推，最终替换的总数达到总元素个数时结束
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            int cur = i;
            int prev = nums[cur];
            // do while 的使用场景是一上来是要跳出循环的
            // 先做一次以后，循环执行，用于判断回到原点时使用
            do {
                // 长为len的 ring buffer
                // i位置经过k次移动到 (i + k) % len 位置
                int next = (cur+k) % n;
                int tmp = nums[next];
                nums[next] = prev;
                prev = tmp;
                count++;
                if (count == n)
                    return;
                cur = next;
            } while (cur != i); // 注意 while 写在后面是要以;结束
        }
    }
};