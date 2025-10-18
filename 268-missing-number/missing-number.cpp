#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();       // Total number of elements in the input array (which is missing 1 number)
        int sum = 0;               // Variable to store the sum of all elements in the input array
        int expsum = 0;            // Variable to store the expected sum from 0 to n

        // Calculate expected sum of numbers from 0 to n using loop
        for (int i = 0; i <= n; i++) {
            expsum += i;
        }

        // Calculate actual sum of elements present in the array
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        // The missing number is the difference between expected sum and actual sum
        return expsum - sum;
    }
};
