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
    ListNode* oddEvenList(ListNode* head) {
        vector<int> a;
        if(head==NULL||head->next==NULL) return head;
        ListNode* temp1= head;
        while(temp1!=NULL){
            a.push_back(temp1->val);
            if(temp1->next==NULL)break;
            temp1=temp1->next->next;
        }
        ListNode* temp2= head->next;
        while(temp2!=NULL){
            a.push_back(temp2->val);
            if(temp2->next==NULL)break;
            temp2=temp2->next->next;
        }
        ListNode* temp=head;
        int ind=0;
        while(temp!=NULL){
            temp->val=a[ind];
            ind++;
            temp=temp->next;
        }
        return head;
    }
};
