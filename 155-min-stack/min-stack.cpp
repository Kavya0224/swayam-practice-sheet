class MinStack {
public:
    // Stack to store pairs: (value, current minimum)
    stack<pair<int, int>> s;

    // Constructor
    MinStack() {
        // No initialization needed here
    }

    // Pushes a new value onto the stack
    void push(int val) {
        if (s.empty()) {
            // If the stack is empty, the current value is the minimum
            s.push({val, val});
        } else {
            // Otherwise, compare with current minimum and update
            int minVal = min(val, s.top().second);
            s.push({val, minVal});
        }
    }

    // Removes the top element from the stack
    void pop() {
        s.pop();
    }

    // Returns the top element of the stack
    int top() {
        return s.top().first;
    }

    // Retrieves the minimum element in the stack
    int getMin() {
        return s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
