class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // If no flowers need to be planted, it's always possible
        if (n == 0) {
            return true;
        }

        // Iterate through each plot in the flowerbed
        for (int i = 0; i < flowerbed.size(); i++) {
            
            // Check if the current plot is empty (0)
            // and both adjacent plots (if they exist) are also empty
            if (flowerbed[i] == 0 &&
                (i == 0 || flowerbed[i - 1] == 0) && // Check left plot (or ignore if first plot)
                (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0)) { // Check right plot (or ignore if last plot)
                
                // Place a flower here
                flowerbed[i] = 1;
                
                // Decrease the number of flowers we still need to plant
                n--;
                
                // If all required flowers are planted, return true
                if (n == 0) {
                    return true;
                }
            }
        }

        // If we finish the loop and still have flowers left to plant, return false
        return false;
    }
};
