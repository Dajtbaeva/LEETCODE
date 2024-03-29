1470. Shuffle the Array
Input: nums = [2,5,1,3,4,7], n = 3
Output: [2,3,5,4,1,7] 
Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7].

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        int a = n;
        for(int i = 0; i < n; i++){
            ans.push_back(nums[i]);
            ans.push_back(nums[a]);
            a++;
        }
        return ans;
    }
};