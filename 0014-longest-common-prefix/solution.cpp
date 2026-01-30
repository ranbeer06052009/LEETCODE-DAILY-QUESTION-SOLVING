class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minm=2000;
        int ind=-1;
        for(int i=0; i<strs.size();i++){
            if(strs[i].size()<minm){
                minm=strs[i].size();
                ind=i;
            }
        }
        string ans;
        for(int i=0; i<strs[ind].size();i++){
            for(int j=0; j<strs.size()-1;j++){
                if(strs[j+1][i]!=strs[j][i]){
                    return ans;
                }
            }
            ans.push_back(strs[ind][i]);
        }
        return ans;
    }
};
