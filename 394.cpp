394. Decode String
https://leetcode.com/problems/decode-string/
2[abc]3[cd]ef -> abcabccdcdcdef
3[a2[c]] -> accaccacc

class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ']') st.push(s[i]);
            else{
                string t = "";
                while(!st.empty() && st.top() != '['){
                    t = st.top() + t;
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();
                    string k = "";
                    while(!st.empty() && isdigit(st.top())){
                        k = st.top() + k;
                        st.pop();
                    }
                    int a = stoi(k);
                    while(a--){
                        for(int j = 0; j < t.size(); j++) st.push(t[j]);
                    }
                }
            }
        }
        string res = "";
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
    return res;
    }
};