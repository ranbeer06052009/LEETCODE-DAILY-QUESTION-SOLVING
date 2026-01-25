class Solution{
    private:
    int timer=0;
    void dfs(int node, int parent, vector<int>& vis, vector<int>& tin, vector<int>& low, vector<vector<int>>& adj, vector<vector<int>>& bridges){
        vis[node]=1;
        tin[node]=low[node]=timer++;
        for(auto it: adj[node]){
            if(it==parent)continue;
            if(!vis[it]){
                dfs(it, node, vis, tin, low, adj, bridges);
                low[node]=min(low[node], low[it]);
                if(low[it]>tin[node]){
                    bridges.push_back({node,it});
                }
            }
            else{
                low[node]=min(low[node], tin[it]);
            }
        }
    }
    public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections){
        // SC: O(N+E)+O(N)+O(N)+O(N)+O(E)=O(N+E)
        // TC: O(N+E)+O(N+E)=O(N+E)
        vector<vector<int>> adj(n);
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0), tin(n,-1), low(n,-1);
        vector<vector<int>> bridges;
        // for(int i=0;i<n;i++){
        //     if(!vis[i]){
        //         dfs(i,-1,vis,tin,low,adj,bridges);
        //     }
        // }
        dfs(0,-1,vis,tin,low,adj,bridges);// as the graph is connected
        return bridges;
    }
};
