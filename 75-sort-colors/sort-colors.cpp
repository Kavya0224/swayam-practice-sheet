class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Initialize three pointers:
    // low - boundary for 0s
    // mid - current element under consideration
    // high - boundary for 2s
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    // Process elements until mid crosses high
    while (mid <= high) {
        if (nums[mid] == 0) {
            // Current element is 0, swap it with element at 'low'
            // Then move both 'low' and 'mid' forward
            swap(nums[mid++], nums[low++]);
        } else if (nums[mid] == 1) {
            // Current element is 1, it's in the right place
            // Just move 'mid' forward
            mid++;
        } else {
            // Current element is 2, swap it with element at 'high'
            // Decrease 'high' only (do not move 'mid' yet because the swapped value needs to be checked)
            swap(nums[mid], nums[high--]);
        }
    }
    }
};