class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;          // No houses
        if (n == 1) return nums[0];    // Only one house

        // dp[i] = maximum money that can be robbed from first i houses
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = nums[0];

        // Fill the DP table
        for (int i = 1; i < n; i++) {
            // Either skip current house or rob it
            dp[i + 1] = max(dp[i], dp[i - 1] + nums[i]);
        }

        // The answer is the max money rob-able from all n houses
        return dp[n];
    }
};
