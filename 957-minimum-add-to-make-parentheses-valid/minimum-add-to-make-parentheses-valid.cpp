class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        bool f=false;
        int cnt=0,ans=0;
        for(int i=0;i<n;i++){
            if(cnt==0&&f)f=!f;
            if(!f&&s[i]=='('){
                cnt++;f=!f;
            }else if(!f&&s[i]==')'){
                ans++;
            }else if(f&&s[i]=='('){
                cnt++;
            }else{
                cnt--;
            }
        }
        cout<<ans<<" "<<cnt;
        return ans+cnt;
    }
};