class MyQueue {
private:
    // Stack to handle incoming elements
    stack<int> input;

    // Stack to handle outgoing elements (front of the queue)
    stack<int> output;

public:
    // Constructor: no initialization needed here
    MyQueue() {}

    // Push element x to the back of the queue
    void push(int x) {
        input.push(x);
    }

    // Removes the element from the front of the queue and returns it
    int pop() {
        peek(); // Ensure the front element is at the top of output
        int val = output.top();
        output.pop(); // Remove it
        return val;
    }

    // Get the front element without removing it
    int peek() {
        // Transfer elements from input to output only if output is empty
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top(); // Return the top of output, which is the front of the queue
    }

    // Return whether the queue is empty
    bool empty() {
        // Queue is empty only when both stacks are empty
        return input.empty() && output.empty();
    }
};
