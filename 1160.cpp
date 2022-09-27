1160. Find Words That Can Be Formed by Characters
https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char , int>m , n;
        int sum = 0;
        for(char c : chars)
            m[c]++;

        for(string word : words){
            n = m; 
            int f = 1;
            for(char c : word){
                if(n[c]) n[c]--;
                else{
                    f = 0;
                    break;
                }
            }
            if(f) sum += word.size();
        }
        return sum;
    }
};