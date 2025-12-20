class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_map<int, int> mp;
        int maxVal = 0;

        // Sum points for each number
        for (int x : nums) {
            mp[x] += x;
            maxVal = max(maxVal, x);
        }

        // House Robber DP
        vector<int> dp(maxVal + 1, 0);
        dp[0] = 0;
        dp[1] = mp[1];

        for (int i = 2; i <= maxVal; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + mp[i]);
        }

        return dp[maxVal];
    }
};
