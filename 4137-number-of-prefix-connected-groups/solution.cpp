class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        map<string,int> mp;
        for(int i=0; i<words.size(); i++){
            if(words[i].size()>=k){
                string temp="";
                for(int j=0; j<k;j++){
                    temp.push_back(words[i][j]);
               }
                mp[temp]++;
            }
        }
        
        int ans=0;
        for(auto it: mp){
            if(it.second>1) ans++;
        }
        return ans;;
    }
};
