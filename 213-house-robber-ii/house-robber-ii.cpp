class Solution {
public:
    // Helper function to solve linear House Robber problem
    int robLinear(vector<int>& nums, int start, int end) {
        int n = end - start + 1;     // number of houses in this range
        if (n == 0) return 0;        // no houses to rob
        if (n == 1) return nums[start]; // only one house, rob it

        // dp[i] = max money rob-able from first i houses in this range
        vector<int> dp(n + 1, 0);
        dp[0] = 0;                   // base case: no house
        dp[1] = nums[start];          // base case: first house

        // Fill the DP table
        for (int i = 1; i < n; i++) {
            // Either skip current house (dp[i]) or rob it (dp[i-1] + nums[start+i])
            dp[i + 1] = max(dp[i], dp[i - 1] + nums[start + i]);
        }

        return dp[n];                 // max money for this range
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;        // no houses
        if (n == 1) return nums[0];  // only one house

        // Case 1: Rob houses from 0 to n-2 (exclude last house)
        int case1 = robLinear(nums, 0, n - 2);

        // Case 2: Rob houses from 1 to n-1 (exclude first house)
        int case2 = robLinear(nums, 1, n - 1);

        // Take the maximum of both cases
        return max(case1, case2);
    }
};
