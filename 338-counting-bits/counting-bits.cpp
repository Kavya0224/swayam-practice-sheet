
class Solution {
public:
    // Helper function with memoization
    int helper(int i, vector<int>& memo) {
        if (i == 0) return 0; // Base case
        if (memo[i] != -1) return memo[i]; // Already computed

        // Compute number of bits: bits[i] = bits[i/2] + (i % 2)
        memo[i] = helper(i / 2, memo) + (i % 2);
        return memo[i];
    }

    vector<int> countBits(int n) {
        vector<int> memo(n + 1, -1); // Initialize memoization array with -1
        vector<int> ans(n + 1);

        for (int i = 0; i <= n; i++) {
            ans[i] = helper(i, memo); // Compute each number using memo
        }

        return ans;
    }
};

