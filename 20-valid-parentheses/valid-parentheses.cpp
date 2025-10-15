class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;  // Stack to keep track of opening brackets
        // Map closing brackets to their corresponding opening brackets
        unordered_map<char, char> mapping = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s) {
            // If the character is NOT a closing bracket, push it onto the stack
            if (mapping.find(c) == mapping.end()) {
                stack.push(c);
            } 
            // If it is a closing bracket, check if stack is not empty
            // and top of stack is the matching opening bracket
            else if (!stack.empty() && mapping[c] == stack.top()) {
                stack.pop();  // Pop the matched opening bracket
            } else {
                // Either stack is empty or brackets do not match
                return false;
            }
        }

        // After processing all characters, if stack is empty, 
        // all brackets matched correctly
        return stack.empty();        
    }
};
