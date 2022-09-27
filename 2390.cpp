2390. Removing Stars From a String
https://leetcode.com/problems/removing-stars-from-a-string/
Input: s = "leet**cod*e"
Output: "lecoe"
Explanation: Performing the removals from left to right:
- The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
- The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
- The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".
There are no more stars, so we return "lecoe".

class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        string res = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '*' && !st.empty()) st.pop();
            else st.push(s[i]);
        }
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};