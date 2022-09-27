1684. Count the Number of Consistent Strings
Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res = 0;
        unordered_set<char> st;
        for(int i = 0; i < allowed.size(); i++){
            st.insert(allowed[i]);
        }
        bool ok;
        for(int i = 0; i < words.size(); i++){
            ok = true;
            for(int j = 0; j < words[i].size(); j++){
                if(st.find(words[i][j]) != st.end()) continue;
                else ok = false;
            }
            if(ok) res++;
        }
        return res;
    }
};