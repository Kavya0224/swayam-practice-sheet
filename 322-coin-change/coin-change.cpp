class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i] will store the minimum number of coins needed to make up amount i
        // Initialize with a large number (amount + 1 acts as "infinity")
        vector<int> dp(amount + 1, amount + 1);

        // Base case: to make amount 0, we need 0 coins
        dp[0] = 0;

        // Iterate over all amounts from 1 to the target amount
        for (int i = 1; i <= amount; ++i) {
            // Try every coin denomination
            for (int coin : coins) {
                // If the current coin can be used (i.e., i - coin is not negative)
                if (i - coin >= 0) {
                    // Choose the minimum between current dp[i] 
                    // and using one coin + best result for (i - coin)
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }

        // If dp[amount] was never updated, return -1 (no valid combination)
        // Otherwise, return the minimum number of coins found
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};

// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         sort(coins.begin(),coins.end());
//         int n=coins.size()-1;
//         int ct=0;
//         int i=n;
//         while(i>=0){
//             if(amount==0){
//                 return ct;
//             }
//             if(amount>=coins[i]){
//                 ct++;
//                 amount-=coins[i];
//             }
//             else{
//                 i--;
//             }
//         }
//         return -1;
//     }
// };