2315. Count Asterisks
Input: s = "l|*e*et|c**o|*de|"
Output: 2
Explanation: The considered characters are underlined: "l|*e*et|c**o|*de|".
The characters between the first and second '|' are excluded from the answer.
Also, the characters between the third and fourth '|' are excluded from the answer.
There are 2 asterisks considered. Therefore, we return 2.

class Solution {
public:
    int countAsterisks(string s) {
        int res = 0;
        bool ok = false;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '*' && !ok) res++;
            if(s[i] == '|' && !ok) ok = true;
            else if(s[i] == '|' && ok) ok = false; 
        }
        return res;
    }
};