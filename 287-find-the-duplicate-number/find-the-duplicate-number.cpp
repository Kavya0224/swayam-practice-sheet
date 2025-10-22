class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();  // Get the size of the input array

        // Create a counting array to track the frequency of each number
        // The array size is n+1 because numbers range from 1 to n (inclusive)
        vector<int> ct(n + 1);  

        // Iterate through the input numbers
        for (int i = 0; i < n; i++) {
            ct[nums[i]]++;  // Increment the count for the current number

            // If the count becomes more than 1, it's the duplicate
            if (ct[nums[i]] > 1) 
                return nums[i];
        }

        // If no duplicate found (though problem constraints guarantee one)
        return -1;
    }
};
