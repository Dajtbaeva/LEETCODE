260. Single Number III
https://leetcode.com/problems/single-number-iii/
Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> m;
        for(auto x : nums) m[x]++;
        for(auto x : m){
            if(x.second == 1) res.push_back(x.first);
        }
        return res;
    }
};