class Solution {
private:
    int reverse(int n){
        long long ans;
        while(n>0){
            ans=ans*10+n%10;
            n/=10;
        }
        return ans;
    }
public:
    int mirrorDistance(int n) {
        return abs(n-reverse(n));
    }
};
