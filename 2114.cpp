2114. Maximum Number of Words Found in Sentences
https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxi = 0;
        for(int i = 0; i < sentences.size(); i++){
            int s = 1;
            for(int j = 0; j < sentences[i].size(); j++){
                if(sentences[i][j] == ' ') s += 1; 
            }
            if(s > maxi) maxi = s;
        }
        return maxi;
    }
};