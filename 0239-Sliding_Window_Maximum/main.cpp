class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 单调栈（Monotonous Stack，也可以说是单调队列）
        // 典型用途是以O(n)找到数组中下一个比自身大的元素（the next greater element, NGE）
        // 本题维护一个单调递减队列，这样队首元素就是窗口的最大值
        // 每次在入队新元素时，将比新入队值小的都可以pop出去，若比队列最小值还要小，就直接插在队尾
        // 因为新插入值是当前窗口中最后一个滑出的，任何更早入队比它小的值就永远不会是最大值了
        // 但是随着窗口移动，栈顶需要退出窗口，所以在维护单调栈的时候要用元素的下标，而非元素实际值
        // 这样当窗口左端已经pass栈顶下标的时候，就要把队首出栈
        // 单调栈的思维很精巧也很高效，是比较高级的栈维护技巧。以下题目类似：
        // 907. Sum of Subarray Minimums
        // 739. Daily Temperatures
        // 503. Next Greater Element II
        vector<int> res;
        if (nums.size() == 0) return res;
        deque<int> dq;
        dq.push_back(0);
        for (int i = 1; i < k; i++) {
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);
        int left = 0, right = k;
        while (right < nums.size()) {
            while (!dq.empty() && nums[dq.back()] <= nums[right])
                dq.pop_back();
            dq.push_back(right++);
            if (dq.front() == left++)
                dq.pop_front();
            res.push_back(nums[dq.front()]);
        }
        return res;
    }
};