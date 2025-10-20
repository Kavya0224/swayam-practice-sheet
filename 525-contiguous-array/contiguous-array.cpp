class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0;        // This variable keeps track of the running sum (treating 0 as -1 and 1 as +1)
        int maxLen = 0;     // Stores the maximum length of subarray with equal number of 0s and 1s

        // Map to store the first occurrence of each sum value.
        // Initialized with {0: -1} to handle the case when a valid subarray starts from index 0
        unordered_map<int, int> seen{{0, -1}};

        // Traverse through the array
        for(int i = 0; i < nums.size(); i++) {
            // Update the sum: treat 0 as -1, and 1 as +1
            sum += nums[i] == 1 ? 1 : -1;

            // If this sum has been seen before, a subarray with equal number of 0s and 1s exists
            if(seen.count(sum)) {
                // Update maxLen if the current subarray is longer
                maxLen = max(maxLen, i - seen[sum]);
            } else {
                // If this sum hasn't been seen, store the index of its first occurrence
                seen[sum] = i;
            }
        }

        return maxLen; // Return the maximum length found
    }
};
