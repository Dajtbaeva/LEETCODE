1859. Sorting the Sentence
Input: s = "is2 sentence4 This1 a3"
Output: "This is a sentence"
Explanation: Sort the words in s to their original positions "This1 is2 a3 sentence4", then remove the numbers.

class Solution {
public:
    string sortSentence(string s) {
        int size = 0;
        for(char c :s)
            if(isdigit(c))
                size = max(size,c-'0');
        
        vector<string> tmp(size);
        
        string str = "";
        for(char c:s)
        {
            if(!isdigit(c) and c != ' ')
                str+=c;
            else if(isdigit(c))
                tmp[(c-'0')-1] =  str;
            else 
                str = "";
        }
        
        s = "";
        for(auto x: tmp)
            s += (x+ " "); 
        return s.substr(0,s.size()-1);

    }
};