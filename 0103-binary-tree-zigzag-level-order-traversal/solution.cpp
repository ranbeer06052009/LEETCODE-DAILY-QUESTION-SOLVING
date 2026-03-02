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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL)return res;
        queue<TreeNode*> q;
        q.push(root);
        bool flag=true;
        while(!q.empty()){
            int n=q.size();
            vector<int>row(n);
            for(int i=0; i<n; i++){
                TreeNode* nd=q.front();
                q.pop();
                int ind=flag?i:n-i-1;
                row[ind]=nd->val;
                if(nd->left!=NULL)q.push(nd->left);
                if(nd->right!=NULL)q.push(nd->right);
            }
            flag=!flag;
            res.push_back(row);
        }
        return res;
    }
};
