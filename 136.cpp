// 136. Single Number
// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> a;
	   for(auto i: nums)
		   a[i]++;
	   for(auto j:a)
		   if(j.second==1)
			   return j.first;
	   return -1;

    }
};