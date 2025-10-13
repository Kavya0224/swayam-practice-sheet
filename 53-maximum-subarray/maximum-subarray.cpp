class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;                    // Current subarray sum
        int maxi = INT_MIN;             // Maximum subarray sum found so far

        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];            // Add current element to the running sum
            maxi = max(maxi, sum);     // Update the maximum if current sum is greater

            // If the current sum becomes negative, reset it to 0
            // (Negative sum won't contribute to max subarray going forward)
            if (sum < 0) {
                sum = 0;
            }
        }

        return maxi;  // Return the maximum subarray sum
    }
};
