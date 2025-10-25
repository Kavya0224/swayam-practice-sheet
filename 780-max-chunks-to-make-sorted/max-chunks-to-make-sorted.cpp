class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // runningSum: sum of elements we've seen so far
        // expectedSum: sum of indices we've seen so far (what the sum would be if sorted)
        // chunks: counts how many chunks (subarrays) we can make
        int runningSum = 0, expectedSum = 0, chunks = 0;

        // Traverse the array from left to right
        for (int i = 0; i < arr.size(); i++) {
            // Accumulate the sum of elements and the sum of indices
            runningSum += arr[i];
            expectedSum += i;

            // If the sums match, it means all elements up to this index
            // are exactly the numbers that belong in this range (in any order).
            // So, we can make a valid chunk here.
            if (runningSum == expectedSum)
                chunks++;
        }

        // Return the total number of chunks we can split the array into
        return chunks;
    }
};
