class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> t(n + 1, 0); // t[i] = min cost to reach top from step i

        // Base case: cost to reach top from top = 0
        t[n] = 0;

        // Fill DP table from the end
        for (int i = n - 1; i >= 0; i--) {
            int oneStep = cost[i] + t[i + 1];
            int twoStep = (i + 2 <= n) ? cost[i] + t[i + 2] : cost[i]; // avoid out-of-bounds
            t[i] = min(oneStep, twoStep);
        }

        // Can start from step 0 or step 1
        return min(t[0], t[1]);
    }
};
