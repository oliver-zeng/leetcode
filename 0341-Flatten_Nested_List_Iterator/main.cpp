/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    stack<NestedInteger> st;
public:
    // 其实这题因为每个元素是，int还是新的vector都是不确定的
    // vector层数不定，所以需要递归的处理问题
    // 因此用dfs或栈实现，且最后的输出是顺序的，因此用栈的话要从后向前入栈
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; i--)
            st.push(nestedList[i]);
    }
    
    int next() {
        NestedInteger tmp = st.top();
        st.pop();
        return tmp.getInteger();
    }
    
    // st.empty()不为空，不代表就真的不为空
    // 比如 [[]] 虽然是空的，但st.empty()不为空
    // 所以必须递归的判断是否为空，也就是用栈把真正的输出找到
    bool hasNext() {
        while (!st.empty()) {
            NestedInteger tmp = st.top();
            if (tmp.isInteger())
                return true;
            st.pop();
            vector<NestedInteger> vec = tmp.getList();
            for (auto iter = vec.rbegin(); iter != vec.rend(); iter++)
                st.push(*iter);
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */