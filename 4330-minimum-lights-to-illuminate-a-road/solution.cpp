class Solution {
public:
    int minLights(vector<int>& lights) {
        int n=lights.size();
        vector<int> diff(n+2,0);
        for(int i=0; i<n; i++){
            int v=lights[i];
            if(v>0){
                diff[max(1,i-v+1)]+=1;
                diff[min(n+1,i+v+2)]-=1;
            }
        }
        for(int i=1; i<=n; i++){
            diff[i]+=diff[i-1];
            //cout<<diff[i];
        }
        int ans=0,cnt=0;
        for(int i=1; i<=n; i++){
            if(diff[i]==0){
                cnt++;
            }else{
                ans+=(cnt%3==0)?(cnt/3):((cnt/3)+1);
                cnt=0;
            }
        }
        ans+=(cnt%3==0)?(cnt/3):((cnt/3)+1);
        return ans;
    }
};
