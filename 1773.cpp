1773. Count Items Matching a Rule
Input: items = [["phone","blue","pixel"],["computer","silver","lenovo"],["phone","gold","iphone"]], ruleKey = "color", ruleValue = "silver"
Output: 1

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int j, res = 0;
        if(ruleKey == "type") j = 0;
        else if(ruleKey == "color") j = 1;
        else if(ruleKey == "name") j = 2;
        for(int i = 0; i < items.size(); i++){
            if(items[i][j] == ruleValue) res++;
        }
        return res;
    }
};