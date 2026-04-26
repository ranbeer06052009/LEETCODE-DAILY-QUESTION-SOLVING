class Solution {
private:
    bool isVow(char c){
        return c=='a'||c=='e'||c=='i'||c=='i'||c=='o'||c=='u';
    }
public:
    string sortVowels(string s) {
        unordered_map<char,int> freq;
        unordered_map<char,int> firstpos;
        int n=s.size();
        vector<int>help(5,0);
        vector<char>ams(n);
        for(int i=0; i<n; i++){
            if(isVow(s[i])){
                freq[s[i]]++;
                if(firstpos.find(s[i])==firstpos.end()){
                firstpos[s[i]]=i;
                }
            }
        }
    vector<int> vowels;
    for(char c:s){
        if(isVow(c))vowels.push_back(c);
    }
    sort(vowels.begin(),vowels.end(),[&](char a,char b){
        if(freq[a]!=freq[b]){
            return freq[a]>freq[b];
        }
        return firstpos[a]<firstpos[b];
    });
    int j=0;
    for(int i=0; i<n; i++){
        if(isVow(s[i])){
            s[i]=vowels[j++];
        }  
    }
    return s;
    }
};
