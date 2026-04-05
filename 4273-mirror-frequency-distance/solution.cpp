class Solution {
public:
    int mirrorFrequency(string s) {
    unordered_map<char,int> freq;
        for(char c:s)freq[c]++;
        unordered_set<char>vis;
        int ans=0;
        for(auto &p:freq){
            char c=p.first;
            if(vis.count(c))continue;
            char m;
            if(isdigit(c)){
                m='9'-(c-'0');
            }else{
                m='z'-(c-'a');
            }
            int f1=freq[c];
            int f2=freq.count(m)?freq[m]:0;
            ans+=abs(f1-f2);
            vis.insert(c);
            vis.insert(m);
        }
        return ans;
    }
};
