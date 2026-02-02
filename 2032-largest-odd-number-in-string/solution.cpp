class Solution {
public:
    string largestOddNumber(string num) {
        string ans="";
        int ind;
        bool flag=false;
        for(int i=num.size()-1; i>=0; i--){
            if(num[i]%2!=0){
                ind=i;
                flag=true;
                break;
            }
        }
        if(!flag) return ans;
        for(int i=0; i<=ind;i++) {
            if(num[0]=='0'&& i==0);
            else{
                ans.push_back(num[i]);
            }
        }
        return ans;
    }
};
