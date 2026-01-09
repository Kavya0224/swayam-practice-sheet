// class Solution {
// public:
//     int longestSubsequence(vector<int>& arr, int diff) {
//         int n=arr.size();
//         int ct=1;
//         int mx=1;
//         for(int i=0;i<n-1;i++){
//             int temp=arr[i];
//             ct=1;
//             for(int j=i+1;j<n;j++){
//                 if(arr[j]-temp==diff){
//                     ct++;
//                     temp=arr[j];
//                 }
//             }
//             mx=max(mx,ct);
//         }
//         return mx;
//     }
// };  
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int, int> dp;
        int ans = 1;

        for (int x : arr) {
            dp[x] = dp[x - diff] + 1;
            ans = max(ans, dp[x]);
        }
        return ans;
    }
};
