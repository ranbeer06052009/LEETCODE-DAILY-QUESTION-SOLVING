class Solution {
public:
    string smallestPalindrome(string s) {
        string st=s;
        int n=s.size();
        int l=0,r=n-1;
        vector<int> ch;
        while(l<r){
            ch.push_back(s[l]-'a');
            l++;
            r--;
        }
        sort(ch.begin(),ch.end());
        int k=ch.size();
        for(int i=0; i<k; i++){
            st[i]=ch[i]+'a';
            st[n-i-1]=ch[i]+'a';
        }
        return st;
    }
};