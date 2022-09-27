338. Counting Bits
https://leetcode.com/problems/counting-bits/
Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101

class Solution {
public:
    int countOne(int n){
        int count = 0;
        while( n>0 ){
            if( n & 1 == 1 ) count++;
            n = n>>1;  
        }
        return count;
    }

    vector<int> countBits(int n){
        vector<int> res;
        for(int i = 0; i <= n; i++){
            res.push_back(countOne(i));
        }
        return res;
    }
};