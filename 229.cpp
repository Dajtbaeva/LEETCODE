229. Majority Element II
https://leetcode.com/problems/majority-element-ii/
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
Input: nums = [3,2,3]
Output: [3]

class Solution {
public:
    static bool comp(pair<int, int> &p1, pair<int, int> &p2){
        return p1.second > p2.second;
    }
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int> m;
        int n = nums.size() / 3;
        for(int i = 0; i < nums.size(); i++) m[nums[i]]++;
        vector<pair<int, int> > res(m.begin(), m.end());
        sort(res.begin(), res.end(), comp);
        vector<int> ans;
        for(int i = 0; i < res.size(); i++)
            if(res[i].second > n) ans.push_back(res[i].first);
        return ans;
    } 
};