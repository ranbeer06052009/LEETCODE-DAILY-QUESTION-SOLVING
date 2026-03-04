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
    void f(TreeNode* root, int k,int &ans,int &cnt){
        if(root==NULL)return;
        f(root->left,k,ans,cnt);
        cnt++;
        if(cnt==k){
            ans=root->val;
            return;
        }
        f(root->right,k,ans,cnt);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans,cnt=0;
        f(root,k,ans,cnt);
        return ans;
    }
};
