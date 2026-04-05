class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        int n=nums.size();

        vector<long long> cost(n,0);
        for(int i=1 ; i<n-1; i++){
            long long nd=max((long long)nums[i-1],(long long)nums[i+1])+1;
            cost[i]=max(0LL,nd-(long long)nums[i]);
        }
        auto better =[](pair<int,long long> a,pair<int,long long>b){
            if(a.first!=b.first)return a.first>b.first?a:b;
            return a.second<=b.second?a:b;
        };
        pair<int,long long>dp0={0,0};
        pair<int,long long>dp1={1,cost[1]};
        for(int i=2; i<n-1; i++){
            pair<int,long long> newdp0=better(dp0,dp1);
            pair<int,long long>newdp1={dp0.first+1,dp0.second+cost[i]};
            dp0=newdp0;
            dp1=newdp1;
        }
        return better(dp0,dp1).second;
    }
};
