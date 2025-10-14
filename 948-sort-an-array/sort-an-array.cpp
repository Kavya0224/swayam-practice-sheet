class Solution {
public:

// Function to merge two sorted halves of the array
void merge(vector<int> &nums, int low, int mid, int high) {
    // Base case: if the range is invalid, return
    if (low >= high) return;

    int l = low;             // Start index of the left half
    int r = mid + 1;         // Start index of the right half
    int k = 0;               // Index for the temporary sorted array
    int size = high - low + 1; // Total elements to merge

    vector<int> sorted(size, 0); // Temporary array to hold sorted elements

    // Merge the two halves in sorted order
    while (l <= mid && r <= high)
        sorted[k++] = nums[l] < nums[r] ? nums[l++] : nums[r++];

    // Copy remaining elements from the left half (if any)
    while (l <= mid) 
        sorted[k++] = nums[l++];

    // Copy remaining elements from the right half (if any)
    while (r <= high) 
        sorted[k++] = nums[r++];

    // Copy the sorted elements back into the original array
    for (k = 0; k < size; k++)
        nums[k + low] = sorted[k];
}

// Recursive merge sort function
void mergeSort(vector<int> &nums, int low, int high) {
    // Base case: if only one element or invalid range, return
    if (low >= high) return;

    // Find the middle index to split the array
    int mid = (high - low) / 2 + low;

    // Recursively sort the left half
    mergeSort(nums, low, mid);

    // Recursively sort the right half
    mergeSort(nums, mid + 1, high);

    // Merge the two sorted halves
    merge(nums, low, mid, high);
}

// Main function to sort the array using merge sort
vector<int> sortArray(vector<int>& nums) {
    mergeSort(nums, 0, nums.size() - 1); // Sort the entire array
    return nums;                         // Return the sorted array
}
};
