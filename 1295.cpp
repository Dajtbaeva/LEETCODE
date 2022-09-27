1295. Find Numbers with Even Number of Digits
https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            int a = 0;
            int b = nums[i];
            while(b > 0){
                a++;
                b /= 10;
            }
            if(a % 2 == 0) cnt++;
        }
        return cnt;
    }
};