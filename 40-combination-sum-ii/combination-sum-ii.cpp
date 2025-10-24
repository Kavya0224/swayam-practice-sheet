class Solution {
public:
    // Main function to find all unique combinations that sum to the target
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Sort the input to handle duplicates easily and enable pruning
        sort(candidates.begin(), candidates.end());
        
        vector<vector<int>> res;  // To store all valid combinations
        vector<int> temp;         // Temporary vector to build combinations

        // Start recursive backtracking from index 0
        helper(candidates, target, 0, temp, res);
        return res;        
    }

    // Recursive helper function for backtracking
    void helper(vector<int>& candidates, int target, int start, 
                vector<int>& temp, vector<vector<int>>& res) {

        // Base case: if target becomes negative, no valid combination possible
        if (target < 0) {
            return;
        }
    
        // Base case: if target becomes 0, store the current combination
        if (target == 0) {
            res.push_back(temp);
            return;
        }
    
        // Loop through candidates starting from the 'start' index
        for (int i = start; i < candidates.size(); i++) {

            // Skip duplicate numbers at the same recursion depth to avoid duplicate combinations
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            
            // If the current candidate exceeds the remaining target, stop exploring further
            // (since the array is sorted, all next numbers will also be too large)
            if (candidates[i] > target) {
                break;
            }
            
            // Choose the current candidate
            temp.push_back(candidates[i]);
            
            // Recurse with reduced target and next index (i + 1) since each number can be used only once
            helper(candidates, target - candidates[i], i + 1, temp, res);
            
            // Backtrack: remove the last chosen number and try the next candidate
            temp.pop_back();
        }
    }
};
