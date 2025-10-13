class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Initialize pointer `j` to keep track of the position to insert the next unique element
        int j = 1;

        // Start from the second element and iterate through the array
        for (int i = 1; i < nums.size(); i++) {
            // If the current element is not equal to the previous one, it's unique
            if (nums[i] != nums[i - 1]) {
                nums[j] = nums[i];  // Place the unique element at position j
                j++;                // Increment j for the next unique position
            }
        }

        // After loop, first `j` elements in `nums` are the unique ones
        return j;  // Return the count of unique elements
    }
};
