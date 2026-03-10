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
    ListNode* deletek(ListNode* head,int k){
        int cnt=0; 
        ListNode* temp=head;
        ListNode* prev=head;
        while(temp!=NULL){
            cnt++;
            if(cnt==k){
                prev->next=prev->next->next;
                delete temp;
                break;
            }
            prev=temp;
            temp=temp->next;
        }
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        if(head==NULL)return head;
        int N=0;
        while(temp!=NULL){
            N++;
            temp=temp->next;
        }
        int k=N-n+1;
        if(k==1){
            ListNode*temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        return deletek(head,k);
    }
};
