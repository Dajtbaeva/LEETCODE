1389. Create Target Array in the Given Order
Input: nums = [0,1,2,3,4], index = [0,1,2,2,1]
Output: [0,4,1,3,2]

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            res.insert(res.begin() + index[i], nums[i]);
        }
        return res;
    }
};