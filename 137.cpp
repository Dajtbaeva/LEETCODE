137. Single Number II
https://leetcode.com/problems/single-number-ii/
Given an integer array nums where every element appears three times except for one, which appears exactly once. 
Find the single element and return it.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> m;
        for(int i = 0; i < nums.size(); i++) m[nums[i]]++;
        for(auto j = m.begin(); j != m.end(); j++) if(j->second == 1) return j->first;
        return 0;
    }
};