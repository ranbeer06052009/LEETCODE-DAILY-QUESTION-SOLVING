class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int d= k%nums.size();
        if(d>0){
            int temp[d];
        int i,j=0;
        for(i=nums.size()-1; i>=(nums.size()-d);i--){
            temp[j]=nums[i];
            j++;
        }
        for(i=(nums.size()-d-1);i>=0;i--){
            nums[i+d]=nums[i];
             }
        int l=0;
        for(i=j-1;i>=0;i--){
            nums[l]=temp[i];
            l++;
        } 
        }
       }
};
