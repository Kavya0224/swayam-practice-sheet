class Solution {
public:
    // Function to find the minimum eating speed `k` such that Koko can eat all bananas in `h` hours.
    int minEatingSpeed(vector<int>& piles, int h) {
        // The minimum possible eating speed is 1 banana per hour.
        // The maximum possible eating speed is the largest pile (we use a large constant as upper bound).
        int left = 1;
        int right = 1000000000;

        // Binary search for the smallest valid eating speed
        while(left <= right){
            int mid = left + (right - left) / 2; // Avoid overflow

            // Check if Koko can eat all bananas at speed `mid` within `h` hours
            if(canEatInTime(piles, mid, h))
                right = mid - 1;  // Try to find a smaller valid speed
            else
                left = mid + 1;   // Increase speed since current one is too slow
        }

        // After the loop, `left` will be pointing to the minimum valid eating speed
        return left;
    }

    // Helper function to check if Koko can eat all bananas at speed `k` in `h` hours
    bool canEatInTime(vector<int>& piles, int k, int h){
        long long hours = 0; // Use long long to prevent overflow

        for(int pile : piles){
            // Divide the pile size by k to get full hours
            int div = pile / k;
            hours += div;

            // If there are remaining bananas, Koko needs one extra hour for that pile
            if(pile % k != 0) hours++;
        }

        // If total hours is within the allowed time `h`, return true
        return hours <= h;
    }
};
