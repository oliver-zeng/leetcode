#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    bool g_debug = false;
    // 此题升序用的是最小堆
    // heap特性为每个节点都是所在子树的最值，因此root节点是整棵树的最值
    // 并且是完全二叉树，所以用数组来实现，因为不会出现null所带来的浪费空间
    vector<int> data;
    int sz;

    //  root 0
    //   0
    //  / \
    // 1   2
    // left 2i+1, right 2i+2, parent (i-1)/2
    // last not leaf count/2 - 1 (since 3/2 - 1 = 0 )

    //  root 1
    //   1
    //  / \
    // 2   3
    // left 2i, right 2i+1, parent i/2
    // last not leaf count/2 (since 3/2 = 1 )

    // shiftXX要向着有序方向移动才有意义
    // only for leaf => push()
    void shiftUp(int i) {
        // if parent exist
        while ((i-1)/2 >= 0 && data[i] < data[(i-1)/2]) {
            swap(data[i], data[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    // from [last not leaf, root] => heapify()
    // or root => pop()
    // heap sort:
    // 1. heapify() + pop()
    // 2. push() + pop()
    void shiftDown(int i) {
        // if child exist
        while (2*i + 1 < sz) {
            int child = 2*i + 1;
            if (child + 1 < sz && data[child] > data[child + 1])
                child++;
            if (data[i] > data[child]) {
                swap(data[i], data[child]);
                i = child;
            } else {
                break;
            }
        }
        if (g_debug) {
            cout << "[Down] ";
            for (auto elm : data)
                cout << elm << ", ";
            cout << endl;
        }
    }

public:
    // 把新节点作为最后一个叶子插入，即放到数组最后一个
    // 通过shiftUp调整堆
    void push(int x) {
        data[sz++] = x;
        shiftUp(sz-1);
    }

    // 把root节点弹出，用最后一个叶子替换
    // 通过shiftDown重新调整堆
    void pop() {
        data[0] = data[sz-1];
        sz--;
        shiftDown(0);
    }

    int top() {
        return data[0];
    }

    void heapify() {
        for (int i = sz/2 - 1; i >= 0; i--) {
            if (g_debug)
                cout << "[heapify] " << i << endl;
            shiftDown(i);
        }
    }

    bool is_empty() {
        return sz == 0;
    }

    void set_size(int x) {
        sz = x;
    }

    // 方法一：直接用heapify建堆，再pop，O(n) + O(n logn)
    vector<int> sortArray(vector<int>& nums) {
        data = nums;
        set_size(nums.size());
        heapify();
        vector<int> res;
        while (!is_empty()) {
            res.push_back(top());
            pop();
        }
        return res;
    }

    // 方法二：逐一push进空堆建堆，再pop，O(n logn) + O(n logn)
    /*vector<int> sortArray(vector<int>& nums) {
        data = vector<int>(nums.size());
        for (auto elm : nums)
            push(elm);
        vector<int> res;
        while (!is_empty()) {
            res.push_back(top());
            pop();
        }
        return res;
    }*/
};


int main() {
    vector<int> vec = { 5,2,3,1 };
    vec = Solution().sortArray(vec);
    for (auto elm : vec)
        cout << elm << ", ";
    cout << endl;
    return 0;
}
