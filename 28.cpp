// Implement strStr()
// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 
// if needle is not part of haystack.
// Input: haystack = "hello", needle = "ll"
// Output: 2

class Solution {
public:
    int strStr(string h, string n) {
        int res = 0;
        for(int j = 0; j < h.size(); j++){
            if(n.substr(0, n.size()) == h.substr(j, n.size())){
                res = j;
                return res;
                return 0;
            } 
        }
        return -1;
    }
};
