844. Backspace String Compare
Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
Note that after backspacing an empty text, the text will continue empty.
Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".

class Solution{
public:
    string solve(string s){
    string temp="";
    for(auto c:s){
        if(c=='#' and temp.size() > 0) temp.pop_back();
        else if(c!='#'){
            temp+=c;
        }
    }
    return temp;
    }
    bool backspaceCompare(string s, string t) {
        if (solve(s)==solve(t))return true;
        return false;
    }
};