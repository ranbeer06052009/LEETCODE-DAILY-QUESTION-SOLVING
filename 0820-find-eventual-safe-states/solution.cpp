class Solution {
private:
    vector<int> topoSort(int &V, vector<vector<int>> adj){
        int indegree[V];
        for(int i=0; i<V; i++)indegree[i]=0;
        for(int i=0; i<V; i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0; i<V; i++){
            if(indegree[i]==0)q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        sort(topo.begin(),topo.end());
        return topo;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<vector<int>> adj(V);
        for(int i=0; i<V; i++){
            for(auto it:graph[i])adj[it].push_back(i);
        }
        return topoSort(V,adj);
    }
};
