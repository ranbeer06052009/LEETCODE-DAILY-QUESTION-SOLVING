class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int n=events.size();
        int i=0;
        int score=0,counter=0;
        while(i<n&&counter<10){
            if(events[i]=="0"||events[i]=="1"||events[i]=="2"||events[i]=="3"||events[i]=="4"||events[i]=="6"){
                int j=events[i][0]-'0';
                score+=j;
            }
            else if(events[i]=="W"){
                counter+=1;
            }
            else if(events[i]=="WD"||events[i]=="NB"){
                score+=1;
            }
            else;
            i++;
        }
        vector<int> a;
        a.push_back(score);
        a.push_back(counter);
        return a;
        
    }
};
