class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n= s.size();
        int cnt=count(s.begin(),s.end(),'1');
        s="1"+s+"1";
        int l=0,m=0,r=0;
        bool left=true;
        int maxm=0;
        for(int i=1; i<=n; i++){
            if(s[i]=='0'&&left){
                l++;
                if(s[i+1]=='1')left=false;
            }else if(s[i]=='1'&& !left){
                m++;
            }else if(s[i]=='0'&& !left){
                r++;
                if(s[i+1]=='1'){
                    maxm=max(l+r,maxm);
                    l=r;r=0;m=0;
                }
            }
        }
        return maxm+cnt;
    }
};