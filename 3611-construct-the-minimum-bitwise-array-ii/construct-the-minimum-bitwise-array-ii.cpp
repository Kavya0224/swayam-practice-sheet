class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];

            // even numbers cannot be formed
            if ((n & 1) == 0) {
                ans[i] = -1;
                continue;
            }

            // count trailing ones
            int k = 0;
            int temp = n;
            while (temp & 1) {
                k++;
                temp >>= 1;
            }

            ans[i] = n - (1 << (k - 1));
        }
        return ans;
    }
};
