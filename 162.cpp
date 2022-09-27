162. Find Peak Element
https://leetcode.com/problems/find-peak-element/
A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, 
return the index to any of the peaks.

Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[nums.size() - 1] > nums[nums.size() - 2]) return nums.size() - 1; // если он вконце
        for(int i = 1; i < nums.size() - 1; i++){
            if(nums[i - 1] < nums[i] && nums[i] > nums[i + 1]) return i;
        } return 0;
    }
};