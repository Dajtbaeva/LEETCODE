1313. Decompress Run-Length Encoded List
Input: nums = [1,2,3,4]
Output: [2,4,4,4]
Explanation: The first pair [1,2] means we have freq = 1 and val = 2 so we generate the array [2].
The second pair [3,4] means we have freq = 3 and val = 4 so we generate [4,4,4].
At the end the concatenation [2] + [4,4,4] is [2,4,4,4].

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector <int> ans;
        for(int i = 0; i < nums.size(); i = i + 2){
            while(nums[i]--){
                ans.push_back(nums[i + 1]);
            }
        }
        return ans;

    }
};