# Length of Last Word

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        a = s.split()
        b = len(a[-1])
        return b


class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        bool ok = false;
        for(int i = s.size(); i > 0; i--){
            if(s[i] == ' ' && ans != 0){
                ok = true;
            }
            if(ok == false) ans += 1;
        }
        
    } 
};