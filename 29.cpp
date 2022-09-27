29. Divide Two Integers
https://leetcode.com/problems/divide-two-integers/
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.

class Solution {
public:
long long int divide(int dividend, int divisor) {
    if(dividend == INT_MIN && divisor == -1) return INT_MAX;
    else{// rest evercase will run on this
        long long int res = dividend/divisor;
        return res;
    }
    }
};

