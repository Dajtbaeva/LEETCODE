// 268. Missing Number
// https://leetcode.com/problems/missing-number/
// Input: nums = [3,0,1]
// Output: 2
// Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 
// 2 is the missing number in the range since it does not appear in nums.

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(); // 3 0 1
        int sumi = n * (n + 1) / 2; // 3 * 4 / 2 = 6
        for(int i = 0; i < n; i++){
            sumi -= nums[i]; // 6 - 3 - 0 - 1 = 2
        }
        return sumi;
    }
};