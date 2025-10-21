class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        
        for (int i = 0; i < nums.size(); ++i) {
            // Remove indices of elements not in the current window
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();
            
            // Remove elements smaller than current from the back
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            
            dq.push_back(i); // Add current element's index

            // Add the maximum for the current window
            if (i >= k - 1)
                result.push_back(nums[dq.front()]);
        }
        
        return result;
    }
};
