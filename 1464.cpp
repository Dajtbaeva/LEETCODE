1464. Maximum Product of Two Elements in an Array
https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
Input: nums = [3,4,5,2]
Output: 12 
Explanation: If you choose the indices i=1 and j=2 (indexed from 0), you will get the maximum value, that is, (nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12. 

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        int res = (nums[0] - 1) * (nums[1] - 1);
        return res;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> q;
        int i = 0;
        while(i < nums.size()){
            q.push(nums[i++]);
        }
        int a = q.top();
        q.pop();
        return (a - 1) * (q.top() - 1);
    }
};