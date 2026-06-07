class Solution {
public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string>ans;
        string s="";
        auto dfs=[&](auto& self,int i,int cost)->void{
            if(i==n){
                ans.push_back(s);
                return;
            }
            s.push_back('0');
            self(self,i+1,cost);
            s.pop_back();
            if((s.empty()||s.back()!='1')&&cost+i<=k){
                s.push_back('1');
                self(self,i+1,cost+i);
                s.pop_back();
            }
        };
        dfs(dfs,0,0);
        return ans;
    }
};
