class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        map<long long , int> mp;
        for(long long i=1; i*i*i<=n; i++){
            for(long long j=i+1;j*j*j+i*i*i<=n;j++){
                mp[i*i*i+j*j*j]++;
            }
        }
        vector<int>good;
        for(auto &[x,c]:mp){
            if(c>=2)good.push_back(x);
        }
        return good;
    }
};
