class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Pointers to track the end of the actual elements in nums1 and nums2
        int midx = m - 1;  // Last valid element in nums1
        int nidx = n - 1;  // Last element in nums2
        int right = m + n - 1;  // Last index of nums1 (including extra space)

        // Start merging from the end to avoid overwriting elements in nums1
        while (nidx >= 0) {
            // If nums1 has elements left and current element is greater than nums2's
            if (midx >= 0 && nums1[midx] > nums2[nidx]) {
                nums1[right] = nums1[midx];  // Move nums1's element to the rightmost available position
                midx--;                      // Move nums1 pointer left
            } else {
                nums1[right] = nums2[nidx];  // Move nums2's element to the rightmost position
                nidx--;                      // Move nums2 pointer left
            }
            right--;  // Move the write pointer to the left
        }        
    }
};
