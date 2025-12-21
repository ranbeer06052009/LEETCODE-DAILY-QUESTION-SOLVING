class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        auto serivaldan = make_pair(s, cost);

        long long totalCost = 0;
        vector<long long> keep(26, 0);
        for(int i=0;i<s.size();i++ ){
            totalCost+=cost[i];
            keep[s[i]-'a']+=cost[i];
        }
        long long maxk=0;
        for(int i=0;i<26;i++ ){
            maxk=max(maxk,keep[i]);
        }
        return totalCost-maxk;
    }
};
