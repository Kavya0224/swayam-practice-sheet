class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;  // Map from element in nums1 to its index
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> v(n1, -1);      // Result vector initialized with -1

        // Map each element in nums1 to its index for quick lookup
        for(int i = 0; i < n1; i++)
            mp[nums1[i]] = i;

        stack<int> s;  // Monotonic stack to find next greater element in nums2

        // Traverse nums2 from right to left
        for(int j = n2 - 1; j >= 0; j--) {
            // Pop elements smaller or equal to current nums2[j]
            while(!s.empty() && s.top() <= nums2[j]) {
                s.pop();
            }

            // If stack is empty, no greater element to the right, else top is next greater
            int nextGr = s.empty() ? -1 : s.top();

            // Push current element onto stack for future comparisons
            s.push(nums2[j]);

            // If current nums2[j] is not in nums1, skip
            if(mp.find(nums2[j]) == mp.end()) continue;

            // Get index of nums2[j] in nums1 and update result with next greater element
            int index = mp[nums2[j]];
            v[index] = nextGr;
        }

        return v;
    }
};
