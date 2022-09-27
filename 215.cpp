215. Kth Largest Element in an Array
https://leetcode.com/problems/kth-largest-element-in-an-array/
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end()); // return nums[nums.size() - k];
        for(int i = 0; i < nums.size(); i++){
            if(k == 1) return nums[i];
            k--;
        } return 0;
    }
};