/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* f(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root ==NULL ) return NULL;
        if(root->val==p->val||root->val==q->val) return root;
        if(root->val<p->val&&root->val<q->val) return f(root->right,p,q);
        else if(root->val>p->val&&root->val>q->val) return f(root->left,p,q);
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return f(root,p,q);
    }
};
