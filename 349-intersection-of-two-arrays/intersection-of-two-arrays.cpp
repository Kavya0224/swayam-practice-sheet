#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());  // Store unique elements from nums1
        unordered_set<int> resultSet;

        // Check if elements in nums2 exist in set1
        for (int num : nums2) {
            if (set1.count(num)) {
                resultSet.insert(num); // Set ensures uniqueness
            }
        }

        // Convert result set to vector
        return vector<int>(resultSet.begin(), resultSet.end());
    }
};
