// 1022. Sum of Root To Leaf Binary Numbers
// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/   
// Input: root = [1,0,1,0,1,0,1]
// Output: 22
// Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22

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
    void helper(TreeNode* root,vector<int> arr,vector<vector<int>> &ans){
        if(!root) return;
        arr.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
           ans.push_back(arr);
            return;
        } /*recursively going left and right until we find the leaf and updating the arr
        and ans vector simultaneously*/
        helper(root->left,arr,ans);
        helper(root->right,arr,ans);
    }
    
    vector<vector<int>> Paths(TreeNode* root){
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<int> arr;
        helper(root,arr,ans);
        return ans;
    }
    int bin_to_dec(vector<int> w){
        int res = 0;
        int j = w.size() - 1;
        for(int i = 0; i < w.size(); i++){
            res += w[i] * pow(2, j);
            j--;
        }
        return res;
    }
    int sumRootToLeaf(TreeNode* root) {
        int sumi = 0;
        vector<vector<int> > res = Paths(root);
        for(int i = 0; i < res.size(); i++){
            sumi += bin_to_dec(res[i]);
        }
        return sumi;
    }
};

class Solution { // DFS
public:
	int ans = 0;
	void solve(TreeNode *root, int buff){
		buff = buff * 2 + root->val;
		if(!root->left && !root->right){
			ans += buff;
			return;
		}

		if(root->left) solve(root->left, buff);
		if(root->right) solve(root->right, buff);
	}

	int sumRootToLeaf(TreeNode* root){
		int buff = 0;
		solve(root, buff);
		return ans;
	}
};
