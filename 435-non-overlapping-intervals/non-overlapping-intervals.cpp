class Solution {
public:
    // Custom comparator to sort intervals by their end time (second element)
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();  // Total number of intervals

        // Step 1: Sort intervals by end time (earlier finishing intervals first)
        sort(intervals.begin(), intervals.end(), cmp);

        int prev = 0;   // Index of the last interval that was included
        int count = 1;  // At least one interval (the first) can always be included

        // Step 2: Iterate through intervals to find the maximum number of non-overlapping intervals
        for(int i = 1; i < n; i++){
            // If the current interval starts after (or exactly when) the previous one ends → no overlap
            if(intervals[i][0] >= intervals[prev][1]){
                prev = i;   // Update the last chosen interval
                count++;    // Increase the count of non-overlapping intervals
            }
            // Else: Overlap found → skip this interval (implicitly means we remove it)
        }

        // Step 3: The minimum number to remove = total intervals - non-overlapping intervals kept
        return n - count;
    }
};
