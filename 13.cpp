// Roman to Integer
// Input: s = "MCMXCIV"
// Output: 1994
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
// 1 <= s.length <= 15
// s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
// It is guaranteed that s is a valid roman numeral in the range [1, 3999].
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman_n;
        roman_n = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}, {'IV', 4},
               {'IX', 9}, {'XL', 40}, {'XC', 90}, {'CD', 400}, {'CM', 900}};
        int res = 0;
        for(int i = 0; i < s.size(); i++){
            int a = roman_n[s[i]];
            if(i != s.size() - 1){
                if(a >= roman_n[s[i + 1]]) res += a;
                else res -= a;
            }
            else res += a;
        }
        return res;
    }
};
// Python
// class Solution:
//     def romanToInt(self, t: str) -> int:
//         roman_n = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000,'IV':4,
//             'IX':9,'XL':40,'XC':90,'CD':400,'CM':900}
//         i, res = 0, 0
//         while i < len(t):
//             if t[i : i + 2] in roman_n and i < len(t):
//                 res += roman_n[t[i : i + 2]]
//                 i += 2
//             else:
//                 res += roman_n[t[i]]
//                 i += 1
//         return res