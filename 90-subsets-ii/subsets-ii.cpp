class Solution {
public:
    // Helper function to generate all unique subsets
    void helper(vector<int>& nums, int i, vector<int>& ans, vector<vector<int>>& all) {
        // Base case: if we've processed all elements
        if (i == nums.size()) {
            all.push_back(ans);  // add current subset to result
            return;
        }

        // ---- Include nums[i] in the subset ----
        ans.push_back(nums[i]);
        helper(nums, i + 1, ans, all);  // recurse for next element
        ans.pop_back();                 // backtrack

        // ---- Exclude nums[i] and skip duplicates ----
        int idx = i + 1;
        // Skip all duplicates of nums[i]
        while (idx < nums.size() && nums[idx] == nums[idx - 1]) {
            idx++;
        }
        // Move index to the next unique element and recurse
        helper(nums, idx, ans, all);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // sort to group duplicates together
        vector<vector<int>> all;
        vector<int> ans;
        helper(nums, 0, ans, all);
        return all;
    }
};
