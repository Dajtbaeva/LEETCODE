557. Reverse Words in a String III
Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

class Solution {
public:
     void reverse(string &str,int l,int r){
        while(l < r){
            swap(str[l++], str[r--]);
        }
        return;
    }
    string reverseWords(string s) {
        int j = 0;
        for(int i = 0; i <= s.size(); i++){
            if(s[i] == ' ' || i == s.size()){
                reverse(s, j, i - 1);
                j = i + 1;
            }
        }
        return s;
    }

};