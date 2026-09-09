class Solution {
public:
    long long countCommas(long long n) {
        long long ans=0;
        if(n==1000000000000000){
            ans+=5;
            n--;
        }
        if(n>=1000000000000){
            ans+=(4*(n-999999999999));
            n=999999999999;
        }
        if(n>=1000000000){
            ans+=(3*(n-999999999));
            n=999999999;
        }
        if(n>=1000000){
            ans+=(2*(n-999999));
            n=999999;
        }
        if(n>=1000){
            ans+=(1*(n-999));
            n=999;
        }
        return ans;
    }
};