class Solution {
public:
    // Function to search for a target value in a rotated sorted array
    int search(vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size() - 1;

        // Perform binary search
        while (st <= end) {
            int mid = st + (end - st) / 2; // Prevent integer overflow

            // If target is found at mid, return its index
            if (nums[mid] == target) {
                return mid;
            }

            // Check if the left half [st...mid] is sorted
            else if (nums[st] <= nums[mid]) {
                // If target lies within the sorted left half
                if (nums[st] <= target && nums[mid] > target) {
                    end = mid - 1; // Search in left half
                }
                else {
                    st = mid + 1; // Search in right half
                }
            }

            // Otherwise, the right half [mid...end] must be sorted
            else {
                // If target lies within the sorted right half
                if (nums[end] >= target && nums[mid] < target) {
                    st = mid + 1; // Search in right half
                }
                else {
                    end = mid - 1; // Search in left half
                }
            }
        }

        // If not found, return -1
        return -1;
    }
};
