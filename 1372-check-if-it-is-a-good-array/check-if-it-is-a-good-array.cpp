class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int n=nums.size();
        int g=nums[0];
        if(n==1){
            if(g==1)return true;
            else return false;
        }
        for(int i=1; i<n; i++){
            g=gcd(g,nums[i]);
        }
        if(g==1)return true;
        return false;
    }
};