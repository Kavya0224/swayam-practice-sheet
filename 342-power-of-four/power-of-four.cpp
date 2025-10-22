class Solution {
public:
    // Function to check if a given integer `n` is a power of four
    bool isPowerOfFour(long long n) {
        // A number is a power of four if:
        // 1. It is a power of two (only one bit is set)
        // 2. That set bit is in an even position (0-based)

        // (n & (n - 1)) == 0 checks if `n` is a power of two.
        // - A power of two has exactly one bit set.
        // - Subtracting 1 flips all bits after the set bit (including it),
        //   so ANDing with the original results in 0 only for powers of two.

        // n % 3 == 1 is a mathematical trick:
        // - Among all powers of 2, only powers of 4 give remainder 1 when divided by 3.
        //   For example:
        //   1  -> 1 % 3 = 1 (4^0)
        //   4  -> 4 % 3 = 1 (4^1)
        //   16 -> 16 % 3 = 1 (4^2)
        //   8  -> 8 % 3 = 2 (not power of 4, but power of 2)

        return (n & (n - 1)) == 0 && n % 3 == 1;
    }
};
