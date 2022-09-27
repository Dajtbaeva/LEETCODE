1002. Find Common Characters
https://leetcode.com/problems/find-common-characters/
Input: words = ["bella","label","roller"]
Output: ["e","l","l"]

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> key(26, INT_MAX);
        vector<string> ans;
        for (auto item : words){
            vector<int> temp(26, 0);
            for (auto c : item) 
                temp[c - 'a']++;
            for (int i = 0; i < 26; i++)
                key[i] = min(key[i], temp[i]);
        }
        
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < key[i]; j++) {
                ans.push_back(string(1, i + 'a'));
            }
        }
        return ans;        
    }
};
