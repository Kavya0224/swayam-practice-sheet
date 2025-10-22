class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Create an unordered_map to store the frequency of each number
        unordered_map<int, int> m;
        
        // Count the occurrences of each number in the input vector
        for (auto x : nums) {
            m[x]++; // Increment the count for number x
        }

        // Iterate through the map to find the number that appears exactly once
        for (auto x : m) {
            if (x.second == 1) {
                return x.first; // Return the number that appears only once
            }
        }
        
        // In case no such number is found (though problem constraints usually guarantee one)
        return -1;
    }
};
