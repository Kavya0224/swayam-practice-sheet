class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0;        // Candidate for majority element
        int majority = 0;   // Counter for tracking balance

        // Loop through each number in the array
        for (int n : nums) {
            // If counter is zero, we choose the current number as a new candidate
            if (majority == 0) {
                res = n;
            }

            // If current number equals candidate, increment the count
            // Else, decrement the count
            majority += (n == res) ? 1 : -1;
        }

        // After this loop, `res` holds the majority element
        return res;        
    }
};
