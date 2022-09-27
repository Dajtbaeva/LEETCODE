2351. First Letter to Appear Twice
Given a string s consisting of lowercase English letters, return the first letter to appear twice.

class Solution {
public:
    char repeatedCharacter(string s) {
        string t = "";
        char res;
        for(int i = 0; i < s.size(); i++){
            if(t.find(s[i]) != string::npos){
                res = s[i];
                break;
            }
            t += s[i];
        }
        return res;
    }
};