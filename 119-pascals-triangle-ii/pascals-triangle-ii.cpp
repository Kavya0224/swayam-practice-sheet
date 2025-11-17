class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> dp(rowIndex+1);
        
        for(int i = 0; i < rowIndex+1; i++) {
            dp[i].resize(i + 1);   // resize row to required size
            dp[i][0] = dp[i][i] = 1; // first and last element are always 1
            
            for(int j = 1; j < i; j++) {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }
        vector<int> ans;
        for(int i=0;i<rowIndex+1;i++){
            ans.push_back(dp[rowIndex][i]);
        }
        return ans;
    }
};
