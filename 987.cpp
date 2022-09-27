987. Vertical Order Traversal of a Binary Tree
https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

class Solution { // DFS
public:
    void FindAnswer(TreeNode* root, int currentX, int currentY, map<int, vector<pair<int,int>>>& resMap)
    {
        // base case - no node, return
        if(root == NULL)
            return;
        
        // left node recursion
        FindAnswer(root->left, currentX - 1, currentY - 1, resMap);
    
        // if we have a new entry, then insert a new entry point
        if(resMap.find(currentX) == resMap.end())
        {
            // insert it as a new vector with a pair of the Y and our value
            resMap[currentX] = vector<pair<int,int>>(1, pair<int,int>(currentY, root->val));
        }
        else
        {
            // insert the new value
            resMap[currentX].push_back(pair<int,int>(currentY, root->val));
            
            // resort the list based on TWO conditions
            // first: if we have two equal positions, place the smaller one earlier
            // second: if they are not equal, place the higher Y value first
            std::sort(resMap[currentX].begin(), resMap[currentX].end(), [](const pair<int,int>& v1, const pair<int,int>& v2) {
                if(v1.first == v2.first)
                    return v1.second < v2.second;
                return v1.first > v2.first;
            });
        }
        
        // right node recursion
        FindAnswer(root->right, currentX + 1, currentY - 1, resMap);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;                    // the answer to return
        map<int, vector<pair<int,int>>> resMap;     // tracking our data
        
        FindAnswer(root, 0, 0, resMap);             // calculate answer
        
        // iterate over our tracked data
        for(pair<int, vector<pair<int,int>>> x : resMap)
        {
            // create a new vector to add to our res
            vector<int> resPartial;
            
            //add each actual value to our vector instead of the index
            for(pair<int,int> partial : x.second)
                resPartial.push_back(partial.second);
            
            // add it to our res
            res.push_back(resPartial);    
        }
        
        return res;
    }
};

class Solution { // BFS
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;
            mp[x][y].insert(node->val);
            if(node->left){
                q.push({node->left,{x-1,y+1}});
            }
            if(node->right){
                q.push({node->right,{x+1,y+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto q:mp){
            vector<int> col;
            for(auto p:q.second){
                col.insert(col.end(),p.second.begin(),p.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
