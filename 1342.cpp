1342. Number of Steps to Reduce a Number to Zero
Given an integer num, return the number of steps to reduce it to zero.

class Solution {
public:
    int numberOfSteps(int num) {
        int res = 0;
        while(num != 0){
            if(num % 2 == 0){
                num /= 2;
                res++;
            }
            else{
                num -= 1;
                res++;
            }
        }
        return res;
    }
};