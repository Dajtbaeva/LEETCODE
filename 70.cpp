// Climbing Stairs
// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step
class Solution {
public:
    int climbStairs(int n) {
        if(n > 0 && n < 3) return n;
        int a = 1, b = 2, tmp;
        for(int i = 2; i < n; i++){
            tmp = b;
            b = b + a;
            a = tmp;
        }
        return b;   
    }
};
