class Solution {
public:
    int minSelection(vector<vector<int>>& a, vector<vector<int>>& t) {
        sort(t.begin(), t.end());
        vector<vector<int>> mt;
        for (const auto& x : t) {
            if (mt.empty() || mt.back()[1] < x[0]) {
                mt.push_back(x);
            } else {
                mt.back()[1] = max(mt.back()[1], x[1]);
            }
        }
        
        sort(a.begin(), a.end());
        
        int ans = 0, i = 0, cov = -2e9;
        priority_queue<int> pq; 
        
        for (const auto& x : mt) {
            int s = x[0], e = x[1];
            if (cov >= e) continue; 
            int req = max(cov, s);
            
            while (req < e || (s == e && req == s)) {
                while (i < a.size() && a[i][0] <= req) {
                    pq.push(a[i][1]);
                    i++;
                }
                if (pq.empty() || pq.top() < req) {
                    return -1;
                }
                
                int best = pq.top();
                if (best == req && req < e) {
                    return -1;
                }
                
                ans++;
                cov = best;
                req = best;
                if (cov >= e) break;
            }
        }
        
        return ans;
    }
};