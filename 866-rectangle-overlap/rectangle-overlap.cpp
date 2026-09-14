class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        bool f=false;;
        int x1=rec1[0],x2=rec1[1],x3=rec1[2],x4=rec1[3];
        int y1=rec2[0],y2=rec2[1],y3=rec2[2],y4=rec2[3];
        if(x1<y3&&y1<x3&&x2<y4&&y2<x4)f=true;
        return f;
    }
};