class Solution {
public:
    // Helper function to generate all permutations using recursion and backtracking
    void helper(vector<int>& nums, vector<vector<int>>& ans, int idx) {
        // Base case: if we've reached the end of the array, we have one complete permutation
        if (idx == nums.size()) {
            ans.push_back(nums);  // store the current permutation
            return;
        }

        // Try placing each remaining element at position 'idx'
        for (int i = idx; i < nums.size(); i++) {
            // Swap current element with the element at the current index
            swap(nums[i], nums[idx]);

            // Recursively generate permutations for the next index
            helper(nums, ans, idx + 1);

            // Backtrack: undo the swap to restore the original array
            swap(nums[i], nums[idx]);
        }
    }

    // Main function to return all permutations of the input array
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;  // to store all permutations
        helper(nums, ans, 0);     // start recursion from index 0
        return ans;
    }
};
