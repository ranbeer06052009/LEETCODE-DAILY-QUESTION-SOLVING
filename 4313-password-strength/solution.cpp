class Solution {
private:
    int pt(int x){
        if(x>='a'&&x<='z')return 1;
        if(x>='A'&&x<='Z')return 2;
        if(x>='0'&&x<='9')return 3;
        if(x=='!'||x=='@'||x=='#'||x=='$')return 5;
        return 0;
    }
public:
    int passwordStrength(string password) {
        unordered_set<int> st;
        int n=password.size();
        int ans=0;
        for(int i=0; i<n; i++){
            int x=password[i];
            if(st.count(x)==0){
                ans+=pt(x);
                st.insert(x);
            }
        }
        return ans;
    }
};
