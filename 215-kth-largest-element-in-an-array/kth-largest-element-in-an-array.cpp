class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Define a min-heap (priority queue with greater comparator)
        // It will store the k largest elements seen so far
        priority_queue<int, vector<int>, greater<int>> pq;

        // Iterate through all elements in the input array
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);  // Push the current element into the min-heap

            // If the size of the heap exceeds k, remove the smallest element
            // This ensures the heap only contains the k largest elements
            if (pq.size() > k) {
                pq.pop();
            }
        }

        // The top of the min-heap is the k-th largest element
        return pq.top();
    }
};
