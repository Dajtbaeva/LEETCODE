1816. Truncate Sentence
Input: s = "Hello how are you Contestant", k = 4
Output: "Hello how are you"

class Solution {
public:
    string truncateSentence(string s, int k) {
        string res = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ') k--;
            if(k == 0){
                break;
            }
            res += s[i]; 
        }
        return res;
    }
};