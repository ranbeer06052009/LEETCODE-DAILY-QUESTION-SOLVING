class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int m=units.size();
        int n=units[0].size();

        if(n==1){
            long long sum=0;
            int minm=1e9;
            for(int i=0; i<m; i++){
                int v=units[i][0];
                minm=min(minm,v);
                if(v>0){
                    sum+=v;
                }
            }
            return (minm<0)?sum+minm:sum;
        }
        long long sum=0;
        int g=1e9;
        int minm=1e9;
        for(int i=0; i<m; i++){
            int m1=1e9,m2=1e9;
            for(int j=0; j<n; j++){
                if(units[i][j]<m1){
                    m2=m1;
                    m1=units[i][j];
                }else if(units[i][j]<m2){
                    m2=units[i][j];
                }
            }
            g=min(g,m1);
            minm=min(minm,m2);
            sum+=m2;
        }
        return (long long)g+sum-minm;
    }
};
