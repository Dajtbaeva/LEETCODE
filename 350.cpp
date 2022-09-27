350. Intersection of Two Arrays II
https://leetcode.com/problems/intersection-of-two-arrays-ii/
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    nums2[j] = -100;
                    res.push_back(nums1[i]);
                    break;
                }
            }
        }
        return res;
    }
};