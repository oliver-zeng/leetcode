class MyQueue {
    stack<int> st;
    stack<int> rst;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        st.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res;
        while (!st.empty()) {
            res = st.top();
            st.pop();
            if (st.size() == 0)
                break;
            rst.push(res);
        }
        while (!rst.empty()) {
            st.push(rst.top());
            rst.pop();
        }
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        int res;
        while (!st.empty()) {
            res = st.top();
            st.pop();
            rst.push(res);
        }
        while (!rst.empty()) {
            st.push(rst.top());
            rst.pop();
        }
        return res;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */