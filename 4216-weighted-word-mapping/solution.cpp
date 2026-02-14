class Solution {

char notochar(int i){
    int j= 25-i;
    int b= 'a';
    char d= static_cast<char>(j+b);
    return d;
}
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int mod=26;
        string ans="";
        for(int i=0; i<words.size(); i++){
            int c=0;
            for(int j=0; j<words[i].size(); j++){
                int b= words[i][j]-'a';
                c=c+weights[b];
                c=c%26;
            }
            char d= notochar(c);
            ans.push_back(d);
        }
        return ans;
    }
};
