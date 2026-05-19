class Solution {
private:
    int M, N;

    void dfs(int i, int j, vector<vector<int>>& board, vector<vector<bool>>& vis){

        if (i < 0 || i >= M || j < 0 || j >= N || vis[i][j] || board[i][j] == 0){
            return;
        }
        
        vis[i][j] = true;
        dfs(i + 1, j, board, vis);
        dfs(i - 1, j, board, vis);
        dfs(i, j + 1, board, vis);
        dfs(i, j - 1, board, vis);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        M = grid.size();
        N = grid[0].size();
        int ans=0;
        vector<vector<bool>> vis(M, vector<bool>(N, false));
        for (int i = 0; i < M; ++i) {
            if (grid[i][0] == 1 && !vis[i][0]) dfs(i, 0, grid, vis);
            if (grid[i][N - 1] == 1 && !vis[i][N - 1]) dfs(i, N - 1, grid,vis);
        }
        for (int j = 0; j < N; ++j) {
            if (grid[0][j] == 1 && !vis[0][j]) dfs(0, j, grid, vis);
            if (grid[M - 1][j] == 1 && !vis[M - 1][j]) dfs(M - 1, j, grid,vis);
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    ans++ ;
                }
            }
        }
        return ans;
    }
};
