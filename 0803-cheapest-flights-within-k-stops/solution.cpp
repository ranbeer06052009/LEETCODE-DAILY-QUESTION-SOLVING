class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        queue<pair<int,pair<int,int>>> q;
        for(int i=0; i<flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int> dist(n,1e9);
        q.push({0,{src,0}});
        while(!q.empty()){
            auto [stops,it]=q.front();
            q.pop();
            auto node=it.first, price=it.second;
            if(stops>k)continue;
            for(auto it:adj[node]){
                int nd=it.first;
                int w=it.second;
                if(price+w<dist[nd]){
                    dist[nd]= price+w ;
                    q.push({stops+1,{nd,dist[nd]}});
                }
            }
        }
        if(dist[dst]==1e9){
            return -1;
        }
        return dist[dst];
    }
};
