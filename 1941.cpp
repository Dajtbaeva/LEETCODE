1941. Check if All Characters Have Equal Number of Occurrences
https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/
Input: s = "abacbc"
Output: true
Explanation: The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.

class Solution {
public:
    bool areOccurrencesEqual(string s) {
        map<char, int> m;
        for(auto i : s) m[i]++;
        int a = m[s[0]];
        for(auto x : m){
            if(x.second != a) return false;
        }
        return true;
    }
};