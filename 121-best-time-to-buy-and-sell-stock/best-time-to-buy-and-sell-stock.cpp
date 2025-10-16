class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Initialize buyPrice with the first day's price
        int buyPrice = prices[0];
        
        // Initialize profit to 0, as we haven't made any transaction yet
        int profit = 0;

        // Loop through the price list starting from the second day
        for (int i = 1; i < prices.size(); i++) {
            // If the current price is less than buyPrice, update buyPrice
            // This means we've found a better (lower) day to buy
            if (buyPrice > prices[i]) {
                buyPrice = prices[i];
            }

            // Calculate the potential profit if we sell on the current day
            // and update the max profit if it's higher than the current profit
            profit = max(profit, prices[i] - buyPrice);
        }

        // Return the maximum profit found
        return profit;        
    }
};
