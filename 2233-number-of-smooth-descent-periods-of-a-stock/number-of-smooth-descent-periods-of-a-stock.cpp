class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long n=prices.size();
        long long temp=0;
        long long ans=n;
        long long ct=0;
        for(int i=1;i<n;i++){
            if(prices[i-1]==prices[i]+1 && i==n-1){
                ct++;
                temp=temp+ct;
                ans=ans+temp;
            }
            else if(prices[i-1]==prices[i]+1){
                ct++;
                temp=temp+ct;
                
            }
            else{
                ans=ans+temp;
                ct=0;

                temp=0;
            }
        }
        return ans;
    }
};