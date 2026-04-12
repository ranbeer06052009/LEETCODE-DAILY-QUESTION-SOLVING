class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        vector<double> angle(3);
        bool flag=false;
        int a=sides[0];
        int b=sides[1];
        int c=sides[2];
        // if(a+b<c||b+c<a||a+c<b)flag=true;
        // if(abs(a-b)>c||abs(b-c)>a||abs(a-c)>b) flag=true;
        // if(flag)return angle;
        double s=(a+b+c)/2.0;
        double area=s*(s-a)*(s-b)*(s-c);
        if(area<=0)return {};
        double cosa=((double)(a*a+b*b-c*c)/((double)2.0*a*b));
        double cosb=((double)(a*a+c*c-b*b)/((double)2.0*a*c));
        double cosc= ((double)(c*c+b*b-a*a)/((double)2.0*c*b));
        //cout<<(a*a+c*c-b*b)/(2*a*c);
        if(cosa>1.0)cosa=1.0;if(cosa<-1.0)cosa=-1.0;
        if(cosb>1.0)cosb=1.0;if(cosb<-1.0)cosb=-1.0;
        if(cosc>1.0)cosc=1.0;if(cosc<-1.0)cosc=-1.0;
        angle[0]=acos(cosa)*(180.0/M_PI);
        angle[1]=acos(cosb)*(180.0/M_PI);
        angle[2]=acos(cosc)*(180.0/M_PI);
        sort(angle.begin(),angle.end());
        return angle;
    }
};
