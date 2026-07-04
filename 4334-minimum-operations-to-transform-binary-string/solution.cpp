class Solution {
public:
    int minOperations(string s1, string s2) {
        int n=s1.size();
        int cnt=0;
        for(int i=0; i<n; i++){
            if(s1[i]!=s2[i]){
                if(s1[i]=='0'&&s2[i]=='1'){
                    cnt+=1;
                }
                if(s1[i]=='1'&&s2[i]=='0'){
                    if(i!=n-1&&s1[i+1]=='1'&&s2[i+1]=='0'){
                        cnt+=1;
                        i++;
                    }else if(i!=n-1&&s1[i+1]=='1'&&s2[i+1]=='1'){
                        cnt+=2;
                        i++;
                    }
                    else if(i!=n-1&&s1[i+1]=='0'&&s2[i+1]=='0'){
                        cnt+=2;
                        i++;
                    }
                    else if(i!=n-1&&s1[i+1]=='0'&&s2[i+1]=='1'){
                        cnt+=3;
                        i++;
                    }
                    else if(i!=0&&s1[i-1]=='0'&&s2[i-1]=='1'){
                        cnt+=2;
                    }
                    else if(i!=0&&s2[i-1]=='0'){
                        cnt+=2;
                    }
                    else if(i!=0&&s2[i-1]=='1'){
                        cnt+=2;
                    }
                    else{
                        return -1;
                    }
                }
            }
        }
        return cnt;
    }  
};
