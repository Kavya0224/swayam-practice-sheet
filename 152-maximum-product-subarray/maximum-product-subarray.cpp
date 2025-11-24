class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int currMax = nums[0]; // dpMax
        int currMin = nums[0]; // dpMin
        int result = nums[0];

        for (int i = 1; i < n; i++) {
            int x = nums[i];

            // When x is negative, max and min swap
            if (x < 0) swap(currMax, currMin);

            currMax = max(x, currMax * x);
            currMin = min(x, currMin * x);

            result = max(result, currMax);
        }

        return result;
    }
};
