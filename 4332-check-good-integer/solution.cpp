class Solution {
public:
    bool checkGoodInteger(int n) {
        int tot=0;
        while(n>0){
            int d=n%10;
            tot+=d*(d-1);
            if(tot>=50){
                return true;
            }
            n/=10;
        }
        return false;
    }
};
