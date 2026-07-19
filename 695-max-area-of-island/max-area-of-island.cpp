class Solution {
public:
    int m, n;

    void dfs(vector<vector<int>>& grid, vector<vector<bool>> &vis, int i, int j,int &a) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0||vis[i][j]){
            return;
        }
        if(!vis[i][j]){
            a++;
            vis[i][j]=true;
        }

        dfs(grid,vis, i + 1, j, a);
        dfs(grid, vis,i - 1, j, a);
        dfs(grid, vis, i, j + 1, a);
        dfs(grid, vis ,i, j - 1,a);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        // for (int i = 0; i < m; i++) {
        //     if (grid[i][0] == 0)
        //         dfs(grid, i, 0);
        //     if (grid[i][n - 1] == 0)
        //         dfs(grid, i, n - 1);
        // }

        // for (int j = 0; j < n; j++) {
        //     if (grid[0][j] == 0)
        //         dfs(grid, 0, j);
        //     if (grid[m - 1][j] == 0)
        //         dfs(grid, m - 1, j);
        // }

        int ans = 0;
        for (int i = 0; i <= m - 1; i++) {
            for (int j = 0; j <= n - 1; j++) {
                if (grid[i][j] == 1&& !vis[i][j]) {
                    int cnt=0;
                    dfs(grid,vis, i, j,cnt);
                    ans=max(ans,cnt);
                }
            }
        }

        return ans;
    }
};