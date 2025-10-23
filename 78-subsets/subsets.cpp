class Solution {
public:
    // Helper function to recursively generate all subsets
    void helper(vector<int>& nums, int i, vector<int>& ans, vector<vector<int>>& all) {
        // Base case: if we've considered all elements
        if (i == nums.size()) {
            all.push_back(ans);  // store the current subset
            return;
        }

        // ---- Include the current element ----
        ans.push_back(nums[i]);          // choose nums[i]
        helper(nums, i + 1, ans, all);   // move to the next element
        ans.pop_back();                  // backtrack: remove nums[i] before exploring next choice

        // ---- Exclude the current element ----
        helper(nums, i + 1, ans, all);   // skip nums[i] and move to next
    }

    // Main function to return all subsets (the power set)
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> all;  // stores all generated subsets
        vector<int> ans;          // temporary vector to store current subset
        helper(nums, 0, ans, all);
        return all;
    }
};
