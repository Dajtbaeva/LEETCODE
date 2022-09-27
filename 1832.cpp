1832. Check if the Sentence Is Pangram
Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
Output: true
Explanation: sentence contains at least one of every letter of the English alphabet.

class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char> s;
        for(int i = 0; i < sentence.size(); i++){
            s.insert(sentence[i]);
        }
        if(s.size() == 26) return true;
        else return false;
    }
};