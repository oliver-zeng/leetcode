#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<stack>
#include<cassert>
using namespace std;

class Solution {
private:
    bool g_debug = false;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // key是nums中出现的数字，value是key出现的频率
        unordered_map<int, int> freq;
        for (auto elm : nums)
            freq[elm]++;
        // pair在堆中是按key排序，所以要把freq中的key与value对调存放
        // 要把要插入到pq中的k+1个元素，与pq中已有的k个元素中的最小值比较
        // 所以需要最小堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // map的遍历没有用index的，都是iter
        for (auto iter = freq.begin(); iter != freq.end(); iter++) {
            //if (pq.size() <= k) { -> wrong, size是从0开始的，[0, k - 1]已经是k个数据
            if (pq.size() < k) {
                // priority_queue没有insert要用push
                pq.push(make_pair(iter->second, iter->first));
                if (g_debug)
                    cout << "<= k number " << iter->second << " times " << iter->first << endl;
            } else {
                if (pq.top().first < iter->second) {
                    pq.pop();
                    pq.push(make_pair(iter->second, iter->first));
                    if (g_debug)
                        cout << "> k number " << iter->second << " times " << iter->first << endl;
                }
            }
        }

        // 这题没要求，前k个要按照频率由高到低输出，所以不需要借助栈逆序输出
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        // 借助栈，逆序输出版本
        //stack<int> reverse;
        //while(!pq.empty()) {
            //if (g_debug)
                //cout << "pq number " << pq.top().second << " times " << pq.top().first << endl;
            //reverse.push(pq.top().second);
            //pq.pop();
        //}

        //vector<int> res;
        //while(!reverse.empty()) {
            //if (g_debug)
                //cout << "reverse number " << reverse.top() << endl;
            //res.push_back(reverse.top());
            //reverse.pop();
        //}
        return res;
    }
};

int main() {
    vector<int> res;
    vector<int> vec = { 1,1,1,2,2,3 };
    int k = 2;
    res = Solution().topKFrequent(vec, k);
    for (auto elm : res)
        cout << elm << " ";
    cout << endl;

    return 0;
}
