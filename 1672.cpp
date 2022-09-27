1672. Richest Customer Wealth
Input: accounts = [[1,2,3],[3,2,1]]
Output: 6
Explanation:
1st customer has wealth = 1 + 2 + 3 = 6
2nd customer has wealth = 3 + 2 + 1 = 6

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxi = 0;
        for(int i = 0; i < accounts.size(); i++){
            int sumi = 0;
            for(int j = 0; j < accounts[i].size(); j++){
                sumi += accounts[i][j];
            }
            if(sumi > maxi) maxi = sumi;
        }
        return maxi;
    }
};