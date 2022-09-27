1614. Maximum Nesting Depth of the Parentheses
Input: s = "(1)+((2))+(((3)))"
Output: 3

class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        int k = 0;
        for(char c : s){
            if(c == '(') k++;
            if(c == ')') k--;
            res = max(res, k);
        }
        return res;
    }
};