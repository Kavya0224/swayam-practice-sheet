class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = -prices[0];
        int sell = 0;
        int cooldown = 0;

        for (int i = 1; i < prices.size(); i++) {
            int prevBuy = buy;
            buy = max(buy, cooldown - prices[i]);
            cooldown = max(cooldown, sell);
            sell = prevBuy + prices[i];
        }
        return max(sell, cooldown);  // ✅ FIX
    }
};
