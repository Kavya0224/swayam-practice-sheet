class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // Create a sorted copy of the array.
        // This represents what the array should look like when fully sorted.
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());

        // Use long long to prevent integer overflow when summing large numbers.
        long long sum1 = 0;  // prefix sum of the original array
        long long sum2 = 0;  // prefix sum of the sorted array
        int chunks = 0;      // count of chunks we can split the array into

        // Traverse the array from left to right
        for (int i = 0; i < arr.size(); ++i) {
            // Add current element to prefix sums of both arrays
            sum1 += arr[i];       // sum of elements seen so far in original array
            sum2 += sorted[i];    // sum of elements seen so far in sorted array

            // When prefix sums are equal, it means both prefixes contain the same multiset of elements
            // (i.e., same numbers with same frequencies, possibly in different order).
            // So, sorting this portion independently will result in the same order as the sorted array.
            if (sum1 == sum2)
                chunks++;  // we can safely make a new chunk here
        }

        // Return the total number of valid chunks found
        return chunks;
    }
};

// class Solution {
// public:
//     int maxChunksToSorted(vector<int>& arr) {
//         // Make a sorted copy of the array
//         // This represents the order the elements should appear in the final sorted array
//         vector<int> nums = arr;
//         sort(nums.begin(), nums.end());

//         // 'm' will store the prefix sum of the sorted array at each index
//         unordered_map<int, int> m;
//         long long expSum = 0;

//         // Compute prefix sums for the sorted array
//         for (int i = 0; i < arr.size(); i++) {
//             expSum += nums[i]; // cumulative sum up to index i
//             m[i] = expSum;     // store in map for quick lookup
//         }

//         long long sum = 0;    // running sum of elements in the original array
//         int chunk = 0;  // count of chunks found

//         // Iterate through the original array
//         for (int i = 0; i < arr.size(); i++) {
//             sum += arr[i];  // add the current element to running sum

//             // If the sum of elements so far matches the sum in the sorted array
//             // it means both prefixes contain the same multiset of numbers.
//             // Hence, we can safely split (form a chunk) here.
//             if (m[i] == sum) {
//                 chunk++;
//             }
//         }

//         // Return the total number of chunks
//         return chunk;
//     }
// };
