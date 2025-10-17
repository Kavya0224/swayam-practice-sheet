class Solution {
public:
    // Function to search for a target value in a rotated sorted array that may contain duplicates
    bool search(vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size() - 1;

        // Perform modified binary search
        while (st <= end) {
            int mid = st + (end - st) / 2;

            // If the target is found at mid, return true
            if (nums[mid] == target) {
                return true;
            }

            // If duplicates make it unclear which side is sorted, move the start pointer by one
            if (nums[mid] == nums[st]) {
                st++;
                continue;
            }

            // If the left half [st...mid] is sorted
            else if (nums[st] <= nums[mid]) {
                // Check if target lies within the sorted left half
                if (nums[st] <= target && nums[mid] > target) {
                    end = mid - 1;  // Search in left half
                } else {
                    st = mid + 1;  // Search in right half
                }
            }

            // Otherwise, the right half [mid...end] must be sorted
            else {
                // Check if target lies within the sorted right half
                if (nums[end] >= target && nums[mid] < target) {
                    st = mid + 1;  // Search in right half
                } else {
                    end = mid - 1;  // Search in left half
                }
            }
        }

        // If target is not found
        return false;
    }
};
