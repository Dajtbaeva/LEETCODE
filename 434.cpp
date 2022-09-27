434. Number of Segments in a String
https://leetcode.com/problems/number-of-segments-in-a-string/
Input: s = "Hello, my name is John"
Output: 5
Explanation: The five segments are ["Hello,", "my", "name", "is", "John"]

class Solution {
public:
    int countSegments(string s) {
        int cnt = 0, n = s.size();
        bool hasChar = false;
        int i = 0;
        while(i < n){
            if(s[i] != ' '){
                while(s[i] != ' ' && i < n) i++;
                cnt++;
            }else i++;
        }
        return cnt;
    }
};
