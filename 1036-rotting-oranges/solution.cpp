class Solution {
private:
    void bfs(queue <pair< pair <int, int>, int>> & q, vector<vector<int>>& grid, int delrow[], int delcol[], int &ans){
        int n= grid.size();
        int m= grid[0].size();
        while(!q.empty()){
            int row= q.front().first.first;
            int col = q.front().first. second;
            ans= q.front(). second;
            q.pop();
            for (int i=0; i<4; i++){
            int nrow= row + delrow[i];
            int mcol= col + delcol[i];
             if( nrow>=0 && nrow< n && mcol>=0 && mcol< m && grid[nrow][mcol]==1 ) {
                grid[nrow][mcol]=2;
                q.push({{nrow,mcol}, ans + 1 });
             }
            }
            
        }
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        int ans=0;
        queue <pair< pair <int, int>, int>> q;
        for ( int i=0; i<n; i++){
            for ( int j=0; j<m; j++){
                if( grid[i][j]==2) q.push({{i,j},0});
            }
        }
        int delrow[]={-1,0,1,0};
        int delcol[]= {0,1,0, -1};
         bfs(q, grid, delrow, delcol, ans);
         for ( int i=0; i<n; i++){
            for ( int j=0; j<m; j++){
                if( grid[i][j]==1) return -1;
            }
        }
        return ans;
    }
};
