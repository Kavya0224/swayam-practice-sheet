class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int range = 0;
        for (int num : nums) range += num;

        // If target is not achievable, return 0
        if ((target + range) % 2 != 0 || abs(target) > range) return 0;

        int s1 = (target + range) / 2;  // Subset sum target

        // DP table: t[i][j] = number of ways to get sum j using first i elements
        vector<vector<int>> t(nums.size() + 1, vector<int>(s1 + 1, 0));

        // Base case: there is 1 way to make sum 0 (by choosing nothing)
        for (int i = 0; i <= nums.size(); i++) {
            t[i][0] = 1;
        }

        // Build the table
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 0; j <= s1; j++) {
                if (nums[i - 1] <= j) {
                    // Include or exclude the current element
                    t[i][j] = t[i - 1][j] + t[i - 1][j - nums[i - 1]];
                } else {
                    // Cannot include the element
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        // The final answer is the number of ways to reach sum s1
        return t[nums.size()][s1];
    }
};
