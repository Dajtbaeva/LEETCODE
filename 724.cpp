724. Find Pivot Index
https://leetcode.com/problems/find-pivot-index/
Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sumi = 0, left = 0;
        for(int i = 0; i < nums.size(); i++){
            sumi += nums[i];
        } 
        for(int i = 0; i < nums.size(); i++){
            if(left == (sumi - left - nums[i])) return i;
            left += nums[i];
        }
        return -1;
    }
};

Input: words = 
["bella", b = 1, e = 1, l = 2, a = 1
"label",  l = 2, a = 1, b = 1, e = 1
"roller" r = 2, l = 2, o = 1, e = 1
