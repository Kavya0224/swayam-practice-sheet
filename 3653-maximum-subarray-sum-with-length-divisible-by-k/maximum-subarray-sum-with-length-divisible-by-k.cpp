class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> pref(n + 1, 0);
        for (int i = 1; i <= n; i++)
            pref[i] = pref[i - 1] + nums[i - 1];

        // Min prefix sum for each modulo class
        vector<long long> minPref(k, LLONG_MAX);

        long long ans = LLONG_MIN;

        for (int j = 0; j <= n; j++) {
            int mod = j % k;

            if (minPref[mod] != LLONG_MAX) {
                ans = max(ans, pref[j] - minPref[mod]);
            }

            // Update min prefix for this modulo
            minPref[mod] = min(minPref[mod], pref[j]);
        }

        return ans;
    }
};
