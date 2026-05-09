class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
        int ans=0;
        if(n<=2)return 0;
        int cnt1=0,cnt0=0;
        for(int i=0; i<n; i++){
            if(s[i]=='1'){
                cnt1++;
            }
        }
        cnt0=n-cnt1;
        int c=(cnt1>0)?cnt1-1:1;
        ans=min({cnt0,cnt1,c});
        if(cnt1<=1)return 0;
        if(n>=2){
            int t=cnt1;
            if(s[0]=='0')t++;
            else t--;
            if(s[n-1]=='0')t++;
            else t--;
            ans=min(ans,t);
        }
        return ans;
    }
};
