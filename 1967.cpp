1967. Number of Strings That Appear as Substrings in Word
Input: patterns = ["a","abc","bc","d"], word = "abc"
Output: 3
Explanation:
- "a" appears as a substring in "abc".
- "abc" appears as a substring in "abc".
- "bc" appears as a substring in "abc".
- "d" does not appear as a substring in "abc".
3 of the strings in patterns appear as a substring in word.

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int a = 0;
        for(int i = 0; i < patterns.size(); i++){
            if(word.find(patterns[i]) != string::npos) a++;
        }
        return a;
    }
};