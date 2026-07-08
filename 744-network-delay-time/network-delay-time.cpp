class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m=times.size();
        vector<int> dist(n+1,1e8),vis(n+1,0);
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0; i<m; i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            adj[u].push_back({v,w});
        }
        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
        > pq;
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int dis=pq.top().first;
            int nd=pq.top().second;
            pq.pop();
            if(dis>dist[nd]){
                continue;
            }
            for(auto &it:adj[nd]){
                int wt=it.second;
                int adjnd=it.first;
                if(dis+wt<dist[adjnd]){
                    dist[adjnd]=dis+wt;
                    pq.push({dist[adjnd],adjnd});
                }
            }
        }
        int ans=*max_element(dist.begin()+1,dist.end());
        return (ans==1e8)?-1:ans;
    }
};