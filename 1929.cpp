1929. Concatenation of Array
Specifically, ans is the concatenation of two nums arrays.

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp, ans;
        for(int i = 0; i < n; i++){
            temp.push_back(nums[i]);
            ans.push_back(nums[i]);
        }
        ans.insert(ans.end(), temp.begin(), temp.end());
        return ans;
    }
};