class MinStack {
    stack<int> data;
    // 用helper记录data栈中的最小元素
    // 新加入的元素，只有小于等于栈顶元素，才入栈helper。
    // 只有当出栈元素等于栈顶元素时，helper才出栈。
    stack<int> helper;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        data.push(x);
        if (helper.empty())
            helper.push(x);
        else
            if (x <= helper.top())
                helper.push(x);
    }
    
    void pop() {
        if (data.top() == helper.top())
            helper.pop();
        data.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return helper.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */