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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* ans= new ListNode();
        ListNode* mover=ans;
        int carr=0;
        while(temp1!=NULL||temp2!=NULL){
            if(temp1==NULL && temp2!=NULL){
                int sum=(temp2->val+carr)%10;
                carr=(temp2->val+carr)/10;
                mover->val=sum;
                ListNode* temp=new ListNode();
                mover->next= temp;
                mover=mover->next;
                temp2=temp2->next;
            }
            else if(temp1!=NULL && temp2==NULL){
                int sum=(temp1->val+carr)%10;
                carr=(temp1->val+carr)/10;
                mover->val=sum;
                ListNode* temp=new ListNode();
                mover->next= temp;
                mover=mover->next;
                temp1=temp1->next;
                
            }
            else if(temp1!=NULL && temp2!=NULL){
                int sum=(temp2->val+carr+temp1->val)%10;
                carr= (temp2->val+carr+temp1->val)/10;
                mover->val=sum;
                ListNode* temp=new ListNode();
                mover->next= temp;
                mover=mover->next;
                temp1=temp1->next;
                temp2=temp2->next;
            }
        }
        if(carr)mover->val=carr;
        else{
            mover=ans;
            while(mover->next->next!=NULL){
                mover=mover->next;
            }
            mover->next=nullptr;
        };
        return ans;
    }
};
