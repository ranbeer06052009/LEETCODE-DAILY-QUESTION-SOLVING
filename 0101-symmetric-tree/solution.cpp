/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool trav(TreeNode* nd1,TreeNode* nd2,bool &ans){
        if(nd1==NULL|| nd2==NULL) {
            ans=(nd1==nd2);
            return ans;}
        if(nd1->val!=nd2->val){
            ans=false;
            // cout<<nd1->val<<nd2->val;
            return ans;
        }
        ans= trav(nd1->right,nd2->left,ans)&&trav(nd1->left,nd2->right,ans);
        return ans;
    }
    bool isSymmetric(TreeNode* root) {
        TreeNode* root1=root->left;
        TreeNode* root2=root->right;
        bool ans=true;
        ans=trav(root1,root2,ans);
        return ans;
    }
};
