class Solution {
public:
    int trap(vector<int>& height) {
        // Pointers start from the second element (left)
        // and the second-to-last element (right).
        int l = 1, r = height.size() - 2;

        // Track the maximum height seen so far from each side.
        int left_max = height[l - 1];
        int right_max = height[r + 1];

        int result = 0;

        while (l <= r) {

            // The side with the smaller max determines the water level.
            if (left_max <= right_max) {

                // Water can be trapped only if left_max is higher.
                result += max(0, left_max - height[l]);

                // Update left_max if current bar is higher.
                left_max = max(left_max, height[l]);

                l++; // Move pointer inward.
            }
            else {

                // Same logic for the right side.
                result += max(0, right_max - height[r]);

                right_max = max(right_max, height[r]);

                r--; // Move pointer inward.
            }
        }

        return result;
    }
};