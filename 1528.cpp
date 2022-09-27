1528. Shuffle String
Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
Output: "leetcode"
Explanation: As shown, "codeleet" becomes "leetcode" after shuffling.

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        for(int i=0;i<indices.size();i++){
            while(indices[i]!=i){
                swap(s[i],s[indices[i]]);
                swap(indices[i],indices[indices[i]]);
            }
        }
    return s;
    }
};