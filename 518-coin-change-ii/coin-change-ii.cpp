class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        // DP table: t[i][j] = number of ways to make amount j using first i coins
        vector<vector<unsigned long long>> t(n + 1, vector<unsigned long long>(amount + 1, 0));

        // ---------- Base Case Initialization ----------
        for (int i = 0; i <= n; i++) {
            // If amount is 0, there is exactly 1 way to make it: use no coins
            t[i][0] = 1;
        }

        for (int j = 1; j <= amount; j++) {
            // If there are 0 coins, we cannot make any positive amount
            t[0][j] = 0;
        }

        // ---------- Build the DP Table ----------
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (coins[i - 1] <= j) {
                    // Option 1: include the coin (unbounded → stay in same row)
                    // Option 2: exclude the coin (move to previous row)
                    t[i][j] = t[i - 1][j] + t[i][j - coins[i - 1]];
                } else {
                    // Cannot include this coin, so just exclude it
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        // ---------- Final Answer ----------
        return t[n][amount];
    }
};
