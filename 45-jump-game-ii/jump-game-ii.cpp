class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0;   // To count the number of jumps
        int far = 0;     // The farthest index we can reach in the current jump range
        int start = 0;   // The starting index of the current jump range

        // Continue until we can reach (or go beyond) the last index
        while (far < nums.size() - 1) {
            int maxi = 0;  // Tracks the farthest point we can reach in the next jump range

            // Explore all indices within the current jump range [start, far]
            for (int i = start; i <= far; i++) {
                // Update the farthest reachable index
                maxi = max(maxi, i + nums[i]);
            }

            // Move to the next jump range:
            // - start becomes the next index after current 'far'
            // - far becomes the new maximum reach
            start = far + 1;
            far = maxi;

            // Increment the jump counter since we completed one jump
            count++;
        }

        // Return the total number of jumps needed to reach the end
        return count;    
    }
};
