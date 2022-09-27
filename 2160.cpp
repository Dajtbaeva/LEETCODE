2160. Minimum Sum of Four Digit Number After Splitting Digits
Input: num = 2932
Output: 52
Explanation: Some possible pairs [new1, new2] are [29, 23], [223, 9], etc.
The minimum sum can be obtained by the pair [29, 23]: 29 + 23 = 52.

class Solution {
public:
    int minimumSum(int num) {
        int res[4];
        for(int i = 0; i < 4; i++){
            res[i] = num % 10;
            num /= 10;
        }
        sort(res, res + 4);
        int n = res[0] * 10 + res[3];
        int m = res[1] * 10 + res[2];
        return n + m;
    }
};