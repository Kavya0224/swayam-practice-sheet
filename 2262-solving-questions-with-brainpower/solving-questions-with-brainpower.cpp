class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        reverse(questions.begin(),questions.end());
        vector<long long> dp(n);
        dp[0]=questions[0][0];
        for(int i=1;i<n;i++){
            long long temp;
            if(i-questions[i][1]-1>=0) temp=dp[i-questions[i][1]-1];
            else temp=0;
            dp[i]=max(dp[i-1],questions[i][0]+temp);
        }
        return dp[n-1];

    }
};