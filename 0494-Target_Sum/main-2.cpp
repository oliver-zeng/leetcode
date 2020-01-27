#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
private:
    bool g_debug = false;
    int sz;

    // 递归函数debug log:
    // 1. 在一进入递归处加log，展示走到的节点，以及进入时的参数，以便于后面选择对参数的消耗比较
    // 2. 在自身递归调用处加log，展示向下递归时的选择路线，此路线的消耗是什么
    // 3. 要在所有返回点加log，展示回溯info（把leaf return的一个最终结果打出来，与一般节点的return区别出来）
    // PS：把每一句log的index在开头用[]标识出来，以醒目区分是index而不是具体值，
    //     并把值都加在:后面，使每句log处于index的何种阶段清晰易懂
    int calcWays(vector<int>& nums, int index, long sum, map<pair<int, long>, int> &memo) {
        if (g_debug) cout << "[" << index << "] enter : sum " << sum << endl;

        pair<int, long> p = make_pair(index, sum);
        if(memo.count(p))
            return memo[p];

        // 递归结束条件是在越界时返回，而不是等于边界时就结束，否则会少了处理到leaf的那一步
        if (index > sz - 1) {
            if (g_debug) cout << "[" << index << "] leaf return : " << ( (sum == 0)? 1 : 0 ) << endl;
            return (sum == 0)? 1 : 0;
        }

        int res = 0;
        // 当然这题必须选，没有不选，无非是选加，还是选减
        if (g_debug) cout << "[" << index << "] choose +" << nums[index] << endl;
        res += calcWays(nums, index + 1, sum + nums[index], memo);
        if (g_debug) cout << "[" << index << "] choose -" << nums[index] << endl;
        res += calcWays(nums, index + 1, sum - nums[index], memo);
        if (g_debug) cout << "[" << index << "] return"<< endl;
        return memo[p] = res;
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        // 对于dp问题，无论是排列（LCS），还是组合（背包）
        // 考虑的都是index选，与不选的问题
        // 只是组合索引是跟顺序无关的，排列需要考虑index与之前索引间最优解相关性
        // 这题加法是满足交换律的，所以选与不选跟顺序无关，是个组合问题

        // 另外所有的组合问题，都可以用递归解
        // 递归既可以从后向前，也可以从前往后
        // 若是从前往后，就是标准的遍历所有递归树从root到leaft分支的问题
        // 从index = 0开始，到index = sz - 1结束递归
        // 积累的递归结果sum，最后若等于S，就是1个解

        sz = nums.size();
        // 第一条debug log里需要打印的值，正是要标记唯一memo的条件
        // 这里特殊的是memo不能用vector，因为sum的值是不确定的，vector取值范围无法确定
        // 就算题目里给了取值范围，申请出来，用不到的空间，也会浪费，所以需要用map
        map<pair<int, long>, int> memo;
        return calcWays(nums, 0, S, memo);
    }
};

int main() {
    //vector<int> nums = {1, 1, 1, 1, 1};
    //cout << Solution().findTargetSumWays(nums, 3) << endl;

    //vector<int> nums = {1, 1, 1};
    //cout << Solution().findTargetSumWays(nums, 2) << endl;

    vector<int> nums = {2,107,109,113,127,131,137,3,2,3,5,7,11,13,17,19,23,29,47,53}
    cout << Solution().findTargetSumWays(nums, 2147483647) << endl;

    return 0;
}
