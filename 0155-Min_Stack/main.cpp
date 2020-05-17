class MinStack {
    stack<int> data;
    // 用单调栈helper记录data栈中的最小元素
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
            // 特别注意，helper应该是个伪单调栈，要把“等于”也考虑进去
            // 因为出栈的时候，只要等于最小元素就会出栈
            // 因此如果有多个相等的最小值，不能只入栈一个
            if (x <= helper.top())
                helper.push(x);
    }
    
    void pop() {
        // 只要等于最小元素就会出栈
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