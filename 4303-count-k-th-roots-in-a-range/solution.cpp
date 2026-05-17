class Solution {
public:
    bool f(long long b, int e, long long m, long long &res){
        res=1;
        for(int i=0; i<e; i++){
            if(res>m/b)return false;
            res*=b;
        }
        return true;
    }
    int countKthRoots(int l, int r, int k) {
        if(k==1){
            return r-l+1;
        }
        long long val;
        int ans=0;
        if(l==0)ans++;
        for(long long b=1;;b++){
            if(!f(b,k,r,val))break;
            if(val>=l&&val<=r)ans++;
        }
        return ans;
    }
};
