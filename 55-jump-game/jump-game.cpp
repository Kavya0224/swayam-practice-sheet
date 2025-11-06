class Solution {
public:
    bool canJump(vector<int>& nums) {
        // Start with the goal set to the last index
        int goal = nums.size() - 1;

        // Traverse the array backward from the second last element
        for (int i = nums.size() - 2; i >= 0; i--) {
            // If we can reach or pass the current goal from index i
            if (i + nums[i] >= goal) {
                // Move the goal to the current index
                goal = i;
            }
        }

        // If the goal has moved all the way to index 0,
        // it means we can reach the end from the start
        return goal == 0;        
    }
};
