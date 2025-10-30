class Solution {
public:
    int helper(int i, vector<int>& cost, int n, vector<int>& t) {
        // Base case: reached or passed the top
        if (i >= n) return 0;

        // Return cached result if available
        if (t[i] != -1) return t[i];

        // Option 1 → take 1 step
        int oneStep = cost[i] + helper(i + 1, cost, n, t);

        // Option 2 → take 2 steps
        int twoStep = cost[i] + helper(i + 2, cost, n, t);

        // Store and return the minimum
        t[i] = min(oneStep, twoStep);
        return t[i];  // ✅ return t[i], not t[n]
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> t(n, -1); // memo array size n is enough

        // You can start from step 0 or step 1
        return min(helper(0, cost, n, t), helper(1, cost, n, t));
    }
};
