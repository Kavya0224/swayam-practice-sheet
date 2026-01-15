class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        unsigned long long sum=0;
        int mn=INT_MAX;
        int ct=0,zero=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum+=abs(matrix[i][j]);
                mn=min(mn,abs(matrix[i][j]));
                if(matrix[i][j]<0) ct++;
                if(matrix[i][j]==0) zero=1;
            }
        }
        if(ct%2==0 || zero==1) return sum;
        return sum-2*mn;

    }
};