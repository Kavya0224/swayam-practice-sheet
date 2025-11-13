class Solution {
public:
    // Helper function to check if there exists a subset with given sum
    bool subsetSum(vector<int>& nums, int sum) {
        // Create DP table: dp[i][j] = true if sum 'j' can be formed using first 'i' elements
        vector<vector<bool>> dp(nums.size() + 1, vector<bool>(sum + 1, false));

        // Base case: sum = 0 can always be achieved by taking no elements
        for (int i = 0; i <= nums.size(); i++) {
            dp[i][0] = true;
        }

        // Fill the DP table
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 1; j <= sum; j++) {
                if (nums[i - 1] <= j) {
                    // Option 1: include current element
                    // Option 2: exclude current element
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
                } else {
                    // Current element cannot be included
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // Final answer: can we make 'sum' using all 'n' elements?
        return dp[nums.size()][sum];
    }

    // Main function: check if array can be partitioned into two equal-sum subsets
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        
        // Step 1: Calculate total sum of the array
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        // Step 2: If total sum is odd, it cannot be divided equally
        if (sum % 2 != 0) 
            return false;

        // Step 3: Otherwise, check if subset with sum = sum/2 exists
        else
            return subsetSum(nums, sum / 2);
    }
};
