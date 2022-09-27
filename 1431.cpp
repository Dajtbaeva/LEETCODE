1431. Kids With the Greatest Number of Candies
Input: candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true] 

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        for(int i = 0; i < candies.size(); i++){
            int cur = candies[i] + extraCandies;
            bool res = true;
            for(int j = 0; j < candies.size(); j++){
            if(cur < candies[j]) res = false;
            }
            ans.push_back(res);
        }
        return ans;
    }
};