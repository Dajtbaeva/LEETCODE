623. Add One Row to Tree
https://leetcode.com/problems/add-one-row-to-tree/
Input: root = [4,2,null,3,1], val = 1, depth = 3
Output: [4,2,null,1,1,3,null,null,1]


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
    void solve(TreeNode*root,int val,int depth,int cd){
       if(cd==depth-1&&root!=NULL){
           TreeNode* rl=root->left;
           TreeNode*rr=root->right;
             TreeNode *l=new TreeNode(val);
           root->left=l;
           l->left=rl;
           TreeNode *r=new TreeNode(val);
             root->right=r;
             r->right=rr;
           return ;
       }
        if(root!=NULL) solve(root->left,val,depth,cd+1);
        if(root!=NULL) solve(root->right,val,depth,cd+1);
       return ;

    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        TreeNode*temp=root;
           if(root==NULL)
               return root;
        if(depth==1){
            TreeNode* res=new TreeNode(val);
             res->left=root;
              return res;
        }
        solve(temp,val,depth,1);
        return root;
    }
};