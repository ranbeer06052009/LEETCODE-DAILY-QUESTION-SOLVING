class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        int n= bulbs.size();
        map<int,pair<int,int>> mp;
        for(int i=0; i<n; i++){
            mp[bulbs[i]].first=i;
            mp[bulbs[i]].second++;
        }
        vector<int> ans;
        for(auto it: mp){
            if(it.second.second%2!=0) ans.push_back(it.first);
        }
        sort(ans.begin(),ans.end());
        return ans; 
    }
};
