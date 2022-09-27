347. Top K Frequent Elements
https://leetcode.com/problems/top-k-frequent-elements/
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

class Solution {
public:
    static bool comp(pair<int, int> &p1, pair<int, int> &p2){
        return p1.second > p2.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for(int i = 0; i < nums.size(); i++) m[nums[i]]++;
        vector<pair<int, int> > res(m.begin(), m.end());
        sort(res.begin(), res.end(), comp);
        vector<int> ans;
        for(int i = 0; i < k; i++) ans.push_back(res[i].first);
        return ans;
    } 
};