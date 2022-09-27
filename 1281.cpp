1281. Subtract the Product and Sum of Digits of an Integer
Given an integer number n, return the difference between the product of its digits and the sum of its digits.

class Solution {
public:
    int subtractProductAndSum(int n){
        int pr = 1;
        int sm = 0;
        while(n > 0){
            int a = n % 10;
            pr *= a;
            sm += a;
            n /= 10;
        }
        return (pr - sm);
    }
};