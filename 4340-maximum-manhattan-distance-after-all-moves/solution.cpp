class Solution {
public:
    int maxDistance(string moves) {
        int x2=0,y2=0,cnt=0;
        int n=moves.size();
        for(int i=0; i<n; i++){
            if(moves[i]=='U')y2+=1;
            else if(moves[i]=='D')y2-=1;
            else if(moves[i]=='L')x2-=1;
            else if(moves[i]=='R')x2+=1;
            else{
                cnt++;
            }
        }
        return abs(x2)+abs(y2)+cnt;
    }
};
