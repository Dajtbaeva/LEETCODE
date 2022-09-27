387. First Unique Character in a String
Input: s = "leetcode"
Output: 0

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> res;
        char c;
        for(int i = 0; i < s.size(); i++){
            res[s[i]]++;
        }
        for(int i = 0; i < s.size(); i++){
            auto it = res.find(s[i]);
            if(it -> second == 1) return i;
        }
        return -1;   
    }
};