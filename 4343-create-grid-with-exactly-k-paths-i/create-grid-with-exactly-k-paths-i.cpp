class Solution {
private:
    long long paths(vector<string> &g,int m,int n,int k){
        vector<long long > dp(n,0);
        if(g[m-1][n-1]=='#')return 0;
        dp[n-1]=1;
        for(int i=m-1;i>=0; i--){
            for(int j=n-1; j>=0;j--){
                if(g[i][j]=='#'){
                    dp[j]=0;
                }else{
                    if(i==m-1&&j==n-1)continue;
                    long long r=(j+1<n)?dp[j+1]:0;
                    long long d=dp[j];
                    dp[j]=min(r+d,k+1LL);
                }
            }
        }
        return dp[0];
    }
    bool f(vector<string> &g,int &m,int &n,int k,int i){
        long long cur=paths(g,m,n,k);
        if(cur==k)return true;
        if(cur<k)return false;
        if(i==m*n)return false;
        int r=i/n;
        int c=i%n;
        if(r==0&&c==0||(r==m-1&&c==n-1)){
            return f(g,m,n,k,i+1);
        }
        g[r][c]='#';
        if(f(g,m,n,k,i+1))return true;
        g[r][c]='.';
        if(f(g,m,n,k,i+1))return true;
        return false;
    }
public:
    vector<string> createGrid(int m, int n, int k) {
        vector<string>grid(m,string (n,'.'));
        long long cnt=paths(grid,m,n,k);
        if(cnt<k){
            return {};
        }
        if(f(grid,m,n,k,0)){
            return grid;
        }
        return {};
    }
};