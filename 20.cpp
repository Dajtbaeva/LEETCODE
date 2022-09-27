// Valid Parentheses
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

class Solution {
public:
    bool isValid(string t) {
    stack<char> a;
    for(int i = 0; i < t.size(); i++){
        if(t[i] == '(' || t[i] == '{' || t[i] == '['){
            a.push(t[i]);
        }
        else if(a.empty()) return false;
        else{
            char top = a.top();
            a.pop();
            if((t[i] != ')' && top == '(') || (t[i] != '}' && top == '{') || (t[i] != ']' && top == '[')){
                return false;
            }
            
        }
    }
    return a.empty();
    }
};