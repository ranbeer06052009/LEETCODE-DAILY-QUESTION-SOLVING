class Solution {
private:
    void dfs(int i, vector<vector<int>>& adjls, vector<int>& vis) {
        vis[i] = 1;
        for (int j : adjls[i]) {
            if (!vis[j]) {
                dfs(j, adjls, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> adjls(V);
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjls[i].push_back(j);
                }
            }
        }
        vector<int> vis(V, 0);
        int count = 0;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                count++;
                dfs(i, adjls, vis);
            }
        }
        return count;
    }
};
