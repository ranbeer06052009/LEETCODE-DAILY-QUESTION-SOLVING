class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        string ans;
        bool ok=true,f=false,f1=false,f2=false;
        for(int i=0;i<n;i++){
            if(ans.size()==11){
                break;
            }
            if(s[i]=='+'&&!f1&&!f){
                f1=true;f=true;
                continue;
            }
            if(s[i]=='-'&&!f1&&!f){
                ok=false;f1=true;f=true;
            }else if((s[i]==' '&&!f)||(s[i]=='0'&&!f)){
                if(s[i]=='0')f=true;
                continue;
            }else if(s[i]>='0'&&s[i]<='9'){
                if(s[i]!='0')f2=true;
                if(f2)ans.push_back(s[i]);
                f=true;
            }else{
                break;
            }
        }
        long long a=0,k=1;
        //for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        for(int i=ans.size()-1;i>=0;i--){
            if(((long long)a+(long long)k*(ans[i]-'0'))>INT_MAX){
                return ok?INT_MAX:INT_MIN;
            }else{
                a+=k*(ans[i]-'0');
                k*=10;
            }
        }
        return ok?a:-a;
    }
};