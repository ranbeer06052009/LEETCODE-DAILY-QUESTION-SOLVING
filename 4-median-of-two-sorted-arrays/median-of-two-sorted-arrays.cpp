class Solution {
public:
    double findMedianSortedArrays(vector<int>& a1, vector<int>& a2) {
        double ans=0;
        int n1=a1.size(),n2=a2.size();
        if(n1>n2){
            return findMedianSortedArrays(a2,a1);
        }
        int n=n1+n2;
        int l=(n1+n2+1)/2;
        int low=0,high=n1;
        while(low<=high){
            int mid1=low+(high-low)/2;
            int mid2=l-mid1;
            int l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
            if(mid1<n1){
                r1=a1[mid1];
            }
            if(mid2<n2){
                r2=a2[mid2];
            }
            if(mid1-1>=0){
                l1=a1[mid1-1];
            }
            if(mid2-1>=0){
                l2=a2[mid2-1];
            }
            if(l1<=r2&&l2<=r1){
                if(n%2==1){
                    return max(l1,l2);
                }else{
                    return ((double)(max(l1,l2)+min(r1,r2)))/2.0;
                }
            }
            else if(l1>r2){
                high=mid1-1;
            }else{
                low=mid1+1;
            }
        }
        return 0;
    }
};