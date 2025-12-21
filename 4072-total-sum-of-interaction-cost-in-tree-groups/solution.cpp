
class Solution {

public:
    long long ans = 0;
    vector<vector<int>> adj;
    vector<int> grp;
    vector<int> total; 

    vector<int>dfs(int u, int parent) {
        vector<int> freq(21, 0);
        freq[grp[u]] = 1;

        for (int v : adj[u]) {
            if (v == parent) continue;

            vector<int> child = dfs(v, u);
            for (int g = 1; g <= 20; g++) {
                long long cnt_sub = child[g];
                long long cnt_out = total[g] - cnt_sub;
                ans += cnt_sub * cnt_out;
            }
            for (int g = 1; g <= 20; g++) {
                freq[g] += child[g];
            }
        }
        return freq;
    }

    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group){

        auto savermiton = make_pair(edges, group);
        ans=0;
        grp=group;
        adj.assign(n, {});
        total.assign(21, 0);

        for (int g : grp) total[g]++;

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0,-1);
        return ans;
    }
};
