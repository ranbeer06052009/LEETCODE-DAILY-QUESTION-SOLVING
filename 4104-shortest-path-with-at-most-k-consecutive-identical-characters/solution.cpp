class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>>adj(n);
        int len=edges.size();
        for(int i=0; i<len; i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
        }
        vector<int>min_cnt(n,INT_MAX);
        priority_queue<tuple<long long, int,int>,vector<tuple<long long, int,int>>,greater<tuple<long long, int,int>>> pq;
        pq.push({0LL,1,0});
        while(!pq.empty()){
            auto[cost,cnt,u]=pq.top();
            pq.pop();
            if(u==n-1){
                return(int)cost;
            }
            if(cnt>=min_cnt[u]){
                continue;
            }
            min_cnt[u]=cnt;
            for(auto &ed: adj[u]){
                int v=ed.first;
                int w=ed.second;
                int ncnt=(labels[v]==labels[u])?cnt+1:1;
                if(ncnt<=k){
                    pq.push({cost+w,ncnt,v});
                }
            }
        }
        return -1;
    }
};
