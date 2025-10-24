class Solution {
public:
    // Recursive helper function to find all unique combinations
    void helper(vector<int>& candidates, int target, vector<vector<int>>& ans, 
                vector<int>& temp, int i, int sum) {

        // Base case: if current sum equals target, store the current combination
        if (sum == target) {
            ans.push_back(temp);
            return;
        }

        // If sum exceeds target or we've processed all candidates, stop recursion
        if (sum > target || i >= candidates.size()) {
            return;
        }

        // -------- Include the current element --------
        // Choose candidates[i] and add it to the current combination
        temp.push_back(candidates[i]);

        // Since we can reuse the same number, we call helper with the same index 'i'
        helper(candidates, target, ans, temp, i, sum + candidates[i]);

        // Backtrack: remove the last added element before trying the next option
        temp.pop_back();

        // -------- Exclude the current element --------
        // Move to the next candidate (i + 1)
        helper(candidates, target, ans, temp, i + 1, sum);
    }

    // Main function to find all unique combinations that sum to the target
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;  // To store all valid combinations
        vector<int> temp;         // Temporary vector for building combinations

        // Start recursion from index 0 with an initial sum of 0
        helper(candidates, target, ans, temp, 0, 0);

        return ans;
    }
};
