258. Add Digits
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

class Solution {
public:
    int addDigits(int num) {
        while(num > 9){
            int a = 0;
            while(num > 0){
                a += num % 10;
                num /= 10;
            }
            num = a;
        }
        return num;
    }
};