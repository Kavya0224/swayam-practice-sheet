class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();  // Get the size of the array

        // Ensure k is within bounds of array size (handle cases where k > n)
        k = k % n;

        // Step 1: Reverse the first part (from start to n-k)
        reverse(nums.begin(), nums.end() - k);

        // Step 2: Reverse the second part (from n-k to end)
        reverse(nums.end() - k, nums.end());

        // Step 3: Reverse the whole array
        reverse(nums.begin(), nums.end());

        // Print the rotated array (optional, usually not needed in LeetCode)
        for (int i = 0; i < n; i++) {
            cout << nums[i];
        }
    }
};
