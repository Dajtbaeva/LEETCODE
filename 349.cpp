// 349. Intersection of Two Arrays
// https://leetcode.com/problems/intersection-of-two-arrays/
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> s{begin(nums1), end(nums1)}; // 1, 2
        for(const int i : nums2){
            if(s.erase(i)) res.push_back(i); // 2
        }
        return res;
    }
};