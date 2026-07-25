class Solution {
public:
    int maxProduct(int n) {
        int max1=-1,max2=1;
        while(n>0){
            int r=n%10;
            if(max1==-1){
                max1=r;
            }else if(r>=max1){
                max2=max1;
                max1=r;
            }else{
                max2=max(max2,r);
            }
            n/=10;
        }
        return max1*max2;
    }
};