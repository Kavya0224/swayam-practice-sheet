class Solution {
public:
    int maxArea(vector<int>& height) {
        // Variable to store the maximum amount of water that can be trapped
        int maxWater = 0;

        // Two pointers: one starting from the left, one from the right
        int lp = 0;
        int rp = height.size() - 1;

        // Loop until the two pointers meet
        while (lp < rp) {
            // Calculate the width between the two lines
            int w = rp - lp;

            // Calculate the height: it's the minimum of the two lines
            int ht = min(height[lp], height[rp]);

            // Calculate the current area and update maxWater if it's larger
            int curr = w * ht;
            maxWater = max(maxWater, curr);

            // Move the pointer with the shorter line inward to try for a taller container
            if (height[lp] < height[rp]) {
                lp++;  // Move left pointer to the right
            } else {
                rp--;  // Move right pointer to the left
            }
        }

        // Return the maximum water area found
        return maxWater;
    }
};
