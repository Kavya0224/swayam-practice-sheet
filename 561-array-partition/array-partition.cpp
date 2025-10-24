class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        // Sort the array in ascending order
        // Sorting ensures that when we take pairs (nums[0], nums[1]), (nums[2], nums[3]), etc.,
        // the smaller element in each pair contributes optimally to maximize the sum of mins.
        sort(nums.begin(), nums.end());
        
        int sum = 0;
        
        // Iterate from the second last element backwards, stepping by 2
        // Since the array is sorted, nums[i] will always be the smaller number in each pair (nums[i], nums[i+1])
        for (int i = nums.size() - 2; i >= 0; i -= 2) {
            sum += nums[i]; // Add the smaller number of each pair
        }
        
        // Return the maximum possible sum of min(ai, bi) for all pairs
        return sum;
    }
};
