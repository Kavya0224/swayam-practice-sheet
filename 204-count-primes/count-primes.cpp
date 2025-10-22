class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;  // Counter to keep track of prime numbers

        // Create a boolean vector to mark primes
        // prime[i] will be true if i is prime, false otherwise
        vector<bool> prime(n + 1, true);

        // 0 and 1 are not prime numbers
        prime[0] = prime[1] = false;

        // Loop through all numbers less than n
        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                cnt++;  // Found a prime number

                // Mark all multiples of i as non-prime
                for (int j = i * 2; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }

        return cnt;  // Return the total count of primes less than n
    }
};
