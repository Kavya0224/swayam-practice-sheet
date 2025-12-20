class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        string s;
        int ct=0;
        int n=strs[0].size();
        for(int i=0;i<n;i++){
            for(int j=1;j<strs.size();j++){
                string t1=strs[j];
                string t2=strs[j-1];
                if(t2[i]>t1[i]){
                    ct++;
                    break;
                }
            }
        }
        return ct;
    }
};