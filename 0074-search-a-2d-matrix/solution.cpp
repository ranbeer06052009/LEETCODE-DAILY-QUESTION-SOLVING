class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i, j,low=0, high=matrix.size()*matrix[0].size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            i=mid/matrix[0].size();
            j=mid % matrix[0].size();
            if(target==matrix[i][j]){
                return true;
            }
            else if(target<matrix[i][j]) high=mid-1;
            else low=mid+1;        
        }
        return false;
    }
};
