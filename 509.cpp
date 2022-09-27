509. Fibonacci Number
https://leetcode.com/problems/fibonacci-number/
Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.

class Solution {
public:
    int fib(int n) {
        vector<int> dp(31,0);
        dp[0]=0;
        dp[1]=1;
        for(int i = 2; i < 31; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};
