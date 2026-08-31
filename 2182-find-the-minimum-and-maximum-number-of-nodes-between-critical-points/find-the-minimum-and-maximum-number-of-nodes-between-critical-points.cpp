/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* h) {
        bool f=false;
        int mx=-1,mn=1e6;
        int id=-1,ls=-1;
        while(h->next->next!=NULL){
            int a,b,c;
            a=h->val;
            b=h->next->val;
            c=h->next->next->val;
            if((a>b&&b<c)||(a<b&&b>c)){
                if(!f){
                    f=true;
                    id=0;ls=0;
                }else{
                    mn=min(mn,id-ls);
                    ls=id;
                }
            }
            if(f)id++;
            h=h->next;
        }
        mx=ls;
        if(ls<=0)return{-1,-1};
        return {mn,ls};
    }
};