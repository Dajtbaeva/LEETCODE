1365. How Many Numbers Are Smaller Than the Current Number

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            int res = 0;
            for(int j = 0; j < nums.size(); j++){
                if(j != i && nums[j] < nums[i]) res++;
            }
            ans.push_back(res);
        }
        return ans;
    }
};