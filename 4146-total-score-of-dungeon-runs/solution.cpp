class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        int n= damage.size();
        vector<long long> S(n+1,0);
        for(int i=1; i<=n; i++)S[i]=S[i-1]+damage[i-1];
        long long temp= hp;
        long long ans  =0;
        for(int k=1; k<=n;k++){
            long long Tk=S[k]-((long long)temp-requirement[k-1]);
            auto it= lower_bound(S.begin(), S.begin()+k, Tk);
            int pos=(int)(it- S.begin());
            ans+=(k-pos);
        }
        return ans;
    }
};
