637. Average of Levels in Binary Tree
https://leetcode.com/problems/average-of-levels-in-binary-tree/
Input: root = [3,9,20,null,null,15,7]
Output: [3.00000,14.50000,11.00000]
Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
Hence return [3, 14.5, 11].

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
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == NULL) return {};
        vector<double> ans;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            double sumi = 0;
            for(int i = 0; i < n; i++){
                TreeNode * node = q.front(); q.pop();
                sumi += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right); 
            }
            ans.push_back(sumi / n);
        }
        return ans;
    }
};  