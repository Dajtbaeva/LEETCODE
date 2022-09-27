1662. Check If Two String Arrays are Equivalent
Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
Output: true
Explanation:
word1 represents string "ab" + "c" -> "abc"
word2 represents string "a" + "bc" -> "abc"
The strings are the same, so return true.

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1, s2;
        for(int i = 0; i < word1.size(); i++){
            s1 += word1[i];
        }
        for(int i = 0; i < word2.size(); i++){
            s2 += word2[i];
        }
        return s1 == s2;
    }
};