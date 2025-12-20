class Solution {
public:
    int climbStairs(int n) {
        // Create a DP array of size n+1 to store the number of ways to reach each step
        vector<int> arr(n + 1);

        // Base cases:
        // There is 1 way to stay at step 0 (do nothing)
        // There is 1 way to reach step 1 (one single step)
        arr[0] = 1;
        arr[1] = 1;

        // Build the DP array from step 2 to n
        // Each step can be reached either from the previous step (i-1)
        // or from two steps below (i-2)
        for (int i = 2; i <= n; i++) {
            arr[i] = arr[i - 1] + arr[i - 2];
        }

        // The answer is the number of ways to reach the nth step
        return arr[n];
    }
};