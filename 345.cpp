345. Reverse Vowels of a String
Input: s = "hello"
Output: "holle"
// POZOR 303ms
class Solution {
public:
    string reverseVowels(string s) {
        string t = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' 
               || s[i] == 'o' || s[i] == 'u' || 
              s[i] == 'A' || s[i] == 'E' || s[i] == 'I' 
               || s[i] == 'O' || s[i] == 'U') t = s[i] + t;
        }
        int j = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' 
               || s[i] == 'o' || s[i] == 'u' ||
              s[i] == 'A' || s[i] == 'E' || s[i] == 'I' 
               || s[i] == 'O' || s[i] == 'U'){
                s[i] = t[j];
                j++;
            } 
        }
        return s;
    }
};