class Solution {
public:
    int robLinear(vector<int>& nums, int start, int end) {
        int n = end - start + 1;
        if (n == 0) return 0;
        if (n == 1) return nums[start];

        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = nums[start];

        for (int i = 1; i < n; i++) {
            dp[i + 1] = max(dp[i], dp[i - 1] + nums[start + i]);
        }

        return dp[n];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // Case 1: Exclude last house
        int case1 = robLinear(nums, 0, n - 2);

        // Case 2: Exclude first house
        int case2 = robLinear(nums, 1, n - 1);

        return max(case1, case2);
    }
};
