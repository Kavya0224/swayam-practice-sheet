class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Hash map to store numbers and their indices
        unordered_map<int, int> numMap;
        int n = nums.size();

        // Traverse the array
        for (int i = 0; i < n; i++) {
            // Calculate the complement needed to reach the target
            int complement = target - nums[i];

            // Check if the complement is already in the map
            if (numMap.count(complement)) {
                // If found, return the indices of the two numbers
                return {numMap[complement], i};
            }

            // Store the current number and its index in the map
            numMap[nums[i]] = i;
        }

        // If no valid pair is found, return an empty vector
        return {};
    }
};
