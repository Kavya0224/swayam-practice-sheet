class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // Stack to keep track of surviving asteroids
        stack<int> stack;

        // Iterate over each asteroid
        for (int a : asteroids) {
            if (a > 0) {
                // Positive asteroids move to the right, always push them
                stack.push(a);
            } else {
                // a < 0 → Negative asteroid moving to the left
                // Check for collisions with previous right-moving asteroids

                // While the stack is not empty AND the top is a right-moving asteroid
                // AND it is smaller than the current left-moving asteroid in magnitude,
                // that means it explodes (gets popped)
                while (!stack.empty() && stack.top() > 0 && stack.top() < -a) {
                    stack.pop();
                }

                // After popping smaller right-moving asteroids,
                // if the stack is empty or the top is also a left-moving asteroid,
                // then no collision — push the current asteroid
                if (stack.empty() || stack.top() < 0) {
                    stack.push(a);
                }

                // If the top asteroid is equal in size but opposite in direction,
                // both explode, so we pop the top (do NOT push current one)
                if (!stack.empty() && stack.top() == -a) {
                    stack.pop();
                }
            }
        }

        // Collect the surviving asteroids from the stack
        vector<int> res(stack.size());
        int i = stack.size() - 1;

        // Since stack is LIFO, reverse the order into the result vector
        while (!stack.empty()) {
            res[i--] = stack.top();
            stack.pop();
        }

        return res;        
    }
};
