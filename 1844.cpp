1844. Replace All Digits with Characters
Input: s = "a1c1e1"
Output: "abcdef"
Explanation: The digits are replaced as follows:
- s[1] -> shift('a',1) = 'b'
- s[3] -> shift('c',1) = 'd'
- s[5] -> shift('e',1) = 'f'

class Solution {
public:
    string replaceDigits(string s) {
        for (int i = 0; i < s.size(); ++i)
            if(isdigit(s[i])) s[i] = s[i - 1] + s[i] - '0';
        return s;
    }
};