class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end()); // Sort first array
        sort(nums2.begin(), nums2.end()); // Sort second array
        int i = 0, j = 0;
        vector<int> ans; // Store unique intersection elements

        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] == nums2[j]) {
                // Add to answer if not already added
                if(ans.empty() || ans.back() != nums1[i]) {
                    ans.push_back(nums1[i]);
                }
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j]) {
                i++; // Move pointer of smaller element
            }
            else {
                j++; // Move pointer of smaller element
            }
        }

        return ans;
    }
};