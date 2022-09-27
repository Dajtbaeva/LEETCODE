804. Unique Morse Code Words
Input: words = ["gin","zen","gig","msg"]
Output: 2
Explanation: The transformation of each word is:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."
There are 2 different transformations: "--...-." and "--...--.".

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string arr[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",
                          ".---","-.-",".-..","--","-.","---",".--.",
                          "--.-",".-.","...","-","..-","...-",".--","-..-","-.--",
                          "--.."};
        unordered_set<string> s;
        string ans;
        for(int i = 0; i < words.size(); i++){
            ans = "";
            for(int j = 0; j < words[i].size(); j++){
                int index = words[i][j] - 'a';
                ans = ans + arr[index];
            }
            s.insert(ans);
        }
       return s.size();
    }
};