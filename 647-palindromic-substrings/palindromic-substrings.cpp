class Solution {
public:
bool isPal(string s,int i,int j){
    if(i>=j) return true;
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
    int countSubstrings(string s) {
        int ct=0;
        for(int i=0;i<s.length();i++){
            ct++;
        }
        for(int i=0;i<s.length()-1;i++){
            for(int j=i+1;j<s.length();j++){
                if(isPal(s,i,j)) ct++;
            }
        }
        return ct;
    }
};
