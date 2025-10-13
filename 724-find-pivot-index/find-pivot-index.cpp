class Solution {
public:
   int pivotIndex(vector<int>& nums) {
    int totalSum = 0;      // Total sum of all elements
    int leftSum = 0;       // Sum of elements to the left of the current index

    // First, calculate the total sum of the array
    for (int num : nums) {
        totalSum += num;
    }

    // Iterate through the array
    for (int i = 0; i < nums.size(); i++) {
        // Right sum is totalSum - leftSum - current element
        int rightSum = totalSum - leftSum - nums[i];

        // If left sum equals right sum, we've found the pivot
        if (leftSum == rightSum) {
            return i;
        }

        // Add current element to left sum before moving to the next index
        leftSum += nums[i];
    }

    // No pivot index found
    return -1;
}

};