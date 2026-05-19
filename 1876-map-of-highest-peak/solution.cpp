class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();
        vector<vector<int>> hc(m,vector<int> (n,-1));
        vector<pair<int,int>> dir={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int,int>> q;
        for(int i=0;i <m;i++){
            for(int j=0; j<n; j++){
                if(isWater[i][j]==1){
                    q.push({i,j});
                    hc[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            auto [r,c]=q.front();q.pop();
            for(auto &[row,col]:dir){
                int nr=r+row;
                int nc=c+col;
                if(nr>=0&&nc>=0&&nr<m&&nc<n&&hc[nr][nc]==-1){
                    hc[nr][nc]=hc[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }
        return hc;
    }
};
