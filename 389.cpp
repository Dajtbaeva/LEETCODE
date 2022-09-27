389. Find the Difference
Input: s = "abcd", t = "abcde"
Output: "e"
Explanation: 'e' is the letter that was added.

class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans;
        for(int i = 0; i < t.size(); i++){
            for(int j = 0; j < s.size(); j++){
                if(t[i] == s[j]){
                    t[i] = '+';
                    s[j] = '-';
                } 
            }
        }
        for(int i = 0; i < t.size(); i++){
            if(t[i] != '+') ans = t[i];
        }
        return ans;
    }
};