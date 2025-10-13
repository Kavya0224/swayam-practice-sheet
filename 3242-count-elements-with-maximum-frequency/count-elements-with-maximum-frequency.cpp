class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        // Hash map to count the frequency of each number
        unordered_map<int, int> freq;

        // `frequency` stores the current maximum frequency
        // `count` stores how many unique numbers have that maximum frequency
        int frequency = 0, count = 0;

        // Count frequency of each number in nums
        for (int num : nums) {
            freq[num]++;
        }

        // Iterate through the frequency map to find:
        // - the maximum frequency
        // - how many numbers have this frequency
        for (auto pair : freq) {
            if (pair.second == frequency) {
                // If this number has the same frequency as current max,
                // increase count of such numbers
                count++;
            } else if (pair.second > frequency) {
                // Found a new higher frequency, update max frequency
                // and reset count to 1 (since this is the first number with this frequency)
                frequency = pair.second;
                count = 1;
            }
        }

        // Total number of elements with the max frequency is frequency * count
        return frequency * count;
    }
};
