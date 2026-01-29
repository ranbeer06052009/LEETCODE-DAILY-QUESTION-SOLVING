class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0;
        int flag=false;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!=' ') {
                flag=true;
                count++;
            }
            if(s[i]==' '&& flag) return count;
        }
        return count;
    }
};
