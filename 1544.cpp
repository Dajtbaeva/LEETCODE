1544. Make The String Great
Input: s = "abBAcC"
Output: ""
Explanation: We have many possible scenarios, and all lead to the same answer. For example:
"abBAcC" --> "aAcC" --> "cC" --> ""
"abBAcC" --> "abBA" --> "aA" --> ""

class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(st.empty()) st.push(s[i]);
            else if(tolower(s[i])==tolower(st.top()) && (isupper(s[i]) && islower(st.top()) || islower(s[i]) && isupper(st.top()))) st.pop();
            else st.push(s[i]);
        }   
        string res = "";
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};