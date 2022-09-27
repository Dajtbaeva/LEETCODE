1221. Split a String in Balanced Strings
Input: s = "RLRRLLRLRL"
Output: 4
Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.

class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0;
        int r = 0;
        int l = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'R') r++;
            else l++;
            if(r == l) res++;
        }
        return res;
    }
};