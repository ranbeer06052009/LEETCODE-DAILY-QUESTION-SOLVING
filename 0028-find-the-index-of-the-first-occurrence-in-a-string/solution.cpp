class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size(),m=needle.size();
        int flag=true;
        for(int i=0; i<n;i++){
            for(int j=i; j<i+m;j++){
                if(needle[j-i]!=haystack[j]){
                    flag=false;
                    break;
                }
                flag=true;
            }
            if(flag){
                return i;
            }
        }
        return -1;
    }
};
