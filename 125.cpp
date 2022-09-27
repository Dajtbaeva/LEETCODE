// 125. Valid Palindrome
// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.

class Solution {
public:
    bool isPalindrome(string s) {
    string res;

    for(int i = 0; i < s.length(); i++){
        if(s[i] >= 'a' && s[i] <= 'z') res += s[i];
        else if(s[i] >= 'A' && s[i] <= 'Z') res += tolower(s[i]);
        else if(s[i] >= '0' && s[i] <= '9') res += s[i];
    }

    for(int i = 0; i < res.length() / 2; i++){
        if(res[i] != res[res.length() - i - 1]) return false;
    }
    return true;
    }
};