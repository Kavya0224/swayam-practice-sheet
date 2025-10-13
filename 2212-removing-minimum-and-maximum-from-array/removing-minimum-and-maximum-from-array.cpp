class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minVal = nums[0], maxVal = nums[0];
        int minIdx = 0, maxIdx = 0;

        // Find indices of min and max
        for (int i = 1; i < n; ++i) {
            if (nums[i] < minVal) {
                minVal = nums[i];
                minIdx = i;
            }
            if (nums[i] > maxVal) {
                maxVal = nums[i];
                maxIdx = i;
            }
        }

        // Ensure minIdx <= maxIdx for simpler logic
        if (minIdx > maxIdx) swap(minIdx, maxIdx);

        // Case 1: remove from front
        int front = maxIdx + 1;

        // Case 2: remove from back
        int back = n - minIdx;

        // Case 3: remove min from front, max from back (or vice versa)
        int both = (minIdx + 1) + (n - maxIdx);

        return min({front, back, both});
    }
};
