// 69. Sqrt(x)
// Given a non-negative integer x, compute and return the square root of x.

class Solution {
public:
    int mySqrt(int x) {
        int ans = sqrt(x);
        return trunc(ans);
    }
};