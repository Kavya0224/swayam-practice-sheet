class Solution {
public:
long long fact(long long n){
    if(n==1) return 1;
    return n*fact(n-1)%1000000007;
}
    int countPermutations(vector<int>& comp) {
        int root=comp[0];
        for(int i=1;i<comp.size();i++){
            if(comp[i]<=root){
                return 0;
            }
        }
        return (fact(comp.size()-1))%(1000000000+7);
    }
};