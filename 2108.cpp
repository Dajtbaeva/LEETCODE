2108. Find First Palindromic String in the Array
Input: words = ["abc","car","ada","racecar","cool"]
Output: "ada"
Explanation: The first string that is palindromic is "ada".
Note that "racecar" is also palindromic, but it is not the first.

class Solution {
public:
    bool pali(string t, int i){
        if(i == t.size()) return true;
        if(t[i] != t[t.size() - i - 1]) return false;
        return pali(t, i + 1);
    }
    string firstPalindrome(vector<string>& words) {
        string res = "";
        for(int i = 0; i < words.size(); i++){
            if(pali(words[i], 0)){
                res = words[i];
                break;
            }
        }
        return res;
    }
};