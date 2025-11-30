class Solution {
public:
    int maxDistinct(string s) {
        int n= s.size();
        set<char> dist;
        for (char c : s) {
            dist.insert(c);
        }
        return dist.size();
    }
};
