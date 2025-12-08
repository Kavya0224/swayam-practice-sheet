class Solution {
public:
    int countTriples(int n) {
      int ct=0;
        for(int a=1;a<n;a++){
            for(int b=a+1;b<n;b++){
                double c=sqrt(a*a+b*b);
                if(c<=n && c==(int)c) ct=ct+2;
            }
        }
        return ct;
    }
};