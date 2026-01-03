class Solution {
public:
    int findLongestChain(vector<vector<int>>& nums) {
         int n = nums.size();
        vector<int> dp(n, 1);  // Every element is an LIS of length 1
        int ans = 1;
        sort(nums.begin(),nums.end());

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j][1] < nums[i][0]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};