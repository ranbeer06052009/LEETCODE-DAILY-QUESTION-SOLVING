class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n=s.size(),m=t.size();
        if(n>m)return false;
        vector<int>pref(n,m),suff(n,-1);
        int j=0;
        for(int i=0; i<m&&j<n; j++){
            while(i<m&&t[i]!=s[j]){
                i++;
            }
            if(i<m){
                pref[j]=i;
                i++;
            }
        }
        if(pref[n-1]<m)return true;
        j=n-1;
        for(int i=m-1; i>=0&&j>=0; j--){
            while(i>=0&&t[i]!=s[j]){
                i--;
            }
            if(i>=0){
                suff[j]=i;
                i--;
            }
        }
        for(int i=0; i<n; i++){
            int l,r;
            if(i==0)l=-1;
            else l=pref[i-1];
            if(i==n-1)r=m;
            else r=suff[i+1];
            if(l<m&&r>=0&&(r-l)>=2){
                return true;
            }
        }
        return false;
    }
};
