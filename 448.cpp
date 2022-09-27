448. Find All Numbers Disappeared in an Array
https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        vector<int> res;
        for(int i = 1; i <= nums.size(); i++){
            v.push_back(i);
        }   
        set<int> s;
        for(int i = 0; i < nums.size(); i++){
            s.insert(nums[i]);
        }
        for(int i = 0; i < v.size(); i++){
            if(s.find(v[i]) == s.end()) res.push_back(v[i]);
        }
        return res;
    }
};