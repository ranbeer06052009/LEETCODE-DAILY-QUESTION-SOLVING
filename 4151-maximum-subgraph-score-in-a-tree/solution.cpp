class Solution {
public:
    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {
        vector<vector<int>> g(n);
        for (auto &e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<int> val(n);
        for (int i = 0; i < n; ++i) val[i] = good[i] ? 1 : -1;

        vector<long long> down(n);
        vector<int> ans(n);

        function<void(int,int)> dfs1 = [&](int u,int p) {
            down[u] = val[u];
            for (int v : g[u]) if (v != p) {
                dfs1(v, u);
                if (down[v] > 0) down[u] += down[v];
            }
        };
        dfs1(0, -1);

        function<void(int,int)> dfs2 = [&](int u,int p) {
            ans[u] = down[u];
            for (int v : g[u]) if (v != p) {
                long long du = down[u], dv = down[v];
                if (down[v] > 0) down[u] -= down[v];
                if (down[u] > 0) down[v] += down[u];
                dfs2(v, u);
                down[u] = du;
                down[v] = dv;
            }
        };
        dfs2(0, -1);
        return ans;
    }
};
