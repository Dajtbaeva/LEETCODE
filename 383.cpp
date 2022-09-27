383. Ransom Note
https://leetcode.com/problems/ransom-note/
Input: ransomNote = "aa", magazine = "ab"
Output: false

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> r;
        unordered_map<char, int> m;
        for(auto x : ransomNote) r[x]++;
        for(auto x : magazine) m[x]++;
        for(auto x : r){
            if(m[x.first] < x.second) return false;
        }
        return true;
    }
};