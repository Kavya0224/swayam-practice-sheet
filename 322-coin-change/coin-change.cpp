class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // Create DP table where t[i][j] represents the minimum number of coins 
        // needed to make amount 'j' using the first 'i' coins.
        vector<vector<int>> t(n + 1, vector<int>(amount + 1, 0));

        // ---------- Initialization ----------
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= amount; j++) {
                if (i == 0)
                    // If there are 0 coins, we cannot make any positive amount.
                    // Use INT_MAX - 1 to avoid integer overflow during addition.
                    t[i][j] = INT_MAX - 1;
                else if (j == 0)
                    // If amount is 0, we need 0 coins.
                    t[i][j] = 0;
            }
        }

        // ---------- Base Case for First Coin ----------
        // If we only have one coin type, we can form amounts that are multiples of it.
        for (int j = 1; j <= amount; j++) {
            if (j % coins[0] == 0)
                // If 'j' is divisible by coins[0], we can make the amount using (j / coins[0]) coins.
                t[1][j] = j / coins[0];
            else
                // Otherwise, it's not possible to form that amount using only this coin.
                t[1][j] = INT_MAX - 1;
        }

        // ---------- Build DP Table (Unbounded Knapsack Logic) ----------
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i - 1] <= j)
                    // Option 1: Exclude the coin (t[i-1][j])
                    // Option 2: Include the coin (1 + t[i][j - coins[i-1]])
                    // Use 't[i][...]' for the include case since coins can be reused.
                    t[i][j] = min(t[i - 1][j], t[i][j - coins[i - 1]] + 1);
                else
                    // If coin value is greater than amount, we cannot include it.
                    t[i][j] = t[i - 1][j];
            }
        }

        // ---------- Result ----------
        int res = t[n][amount];
        // If the result is still "infinite", return -1 (no combination possible)
        return (res == INT_MAX - 1) ? -1 : res;
    }
};