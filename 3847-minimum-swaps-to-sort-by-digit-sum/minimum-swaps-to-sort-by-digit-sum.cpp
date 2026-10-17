class Solution {
public:
    int dsum(int n){
        int sum=0;
        while(n>0){
            sum+=(n%10);
            n/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& a) {
        int n=a.size();
        unordered_map<int,int> pos;
        vector<pair<int,int>> b;
        for(int i=0;i<n;i++){
            b.push_back({a[i],dsum(a[i])});
            pos[a[i]]=i;
        }
        sort(b.begin(),b.end(),[](const auto &c , const auto &d){
            if(c.second==d.second){
                return c.first<=d.first;
            }else{
                return c.second<=d.second;
            }
        });
        int cnt=0;
        for(int i=0;i<n;i++){
            if(b[i].first!=a[i]){
                int id=pos[b[i].first];
                swap(a[i],a[id]);
                pos[a[i]]=i;
                pos[a[id]]=id;
                cnt++;
            }
        }
        return cnt;
    }
};