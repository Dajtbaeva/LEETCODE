189. Rotate Array
https://leetcode.com/problems/rotate-array/
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

class Solution {
public:
    void rotate(vector<int>& nums, int k){
        k %= nums.size();
        int res[nums.size()];
        int pos = 0;
        for(int i = k; i < nums.size(); i++){ // на третьей позиции будет новое начало
            res[i] = nums[pos];
            pos++;
        }
        for(int i = 0; i < k; i++){
            res[i] = nums[pos];
            pos++;
        }
        for(int i = 0; i < nums.size(); i++) nums[i] = res[i];
    }
};