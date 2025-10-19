class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // If the input array is empty, return 0
        if(nums.empty()) return 0;

        // Sort the array to bring consecutive elements together
        sort(nums.begin(), nums.end());

        int ct = 1;         // Current streak count
        int maxi = 1;       // Maximum streak found

        // Iterate through the sorted array starting from index 1
        for(int i = 1; i < nums.size(); i++) {
            // If current element is a duplicate, skip it
            if(nums[i] == nums[i-1]) {
                continue;
            }
            // If current element is consecutive to previous one
            else if(nums[i] == nums[i-1] + 1) {
                ct++;  // Increase the current streak count
            }
            // If not consecutive, reset current streak count
            else {
                ct = 1;
            }

            // Update maximum streak found so far
            maxi = max(maxi, ct);
        }

        return maxi; // Return the length of the longest consecutive sequence
    }
};
