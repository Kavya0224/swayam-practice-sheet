class Solution {
public:
    int smallestRepunitDivByK(int K) {
        // Loop through possible lengths of the repunit number (N = number of digits)
        // A repunit is a number consisting only of 1's, e.g. 1, 11, 111, etc.
        for (int r = 0, N = 1; N <= K; ++N) {
            // Update remainder when the current repunit is divided by K
            // (r * 10 + 1) % K computes the remainder for the next repunit
            r = (r * 10 + 1) % K;

            // If remainder becomes 0, it means the repunit of length N is divisible by K
            if (r == 0)
                return N;
        }

        // If no repunit up to length K is divisible by K, return -1
        // (By the pigeonhole principle, if no remainder repeats and none is 0 by this point,
        // there’s no repunit divisible by K)
        return -1;
    }
};
