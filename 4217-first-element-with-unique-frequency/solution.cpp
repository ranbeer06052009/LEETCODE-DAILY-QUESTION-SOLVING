class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n= nums.size();
        map<int,int> mp; 
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        map<int,int> mp2;
        for(auto &it: mp){
            mp2[it.second]++;
        }
        for(int i=0; i<n; i++){
            if(mp2[mp[nums[i]]]==1) return nums[i];
        }
        return -1;
    }
};
