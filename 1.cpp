// Two sum
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Input: nums = [3,2,4], target = 6
// Output: [1,2]
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> res(2);
        for(int i = 0; i < nums.size(); i++){
            if(m.find(target - nums[i]) != m.end()){
                res[0] = m[target - nums[i]];
                res[1] = i;
                break;
            }else{
                m[nums[i]] = i;
            }
        }
        return res;
    }
};


class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        vector<int> temp = nums;
        int n = nums.size();
        int l = 0;
        int r =  n - 1;
        int sumi = 0;
        sort(nums.begin(),nums.end());
        while(l < r){
            sumi = nums[l] + nums[r];
            if(sumi == target) break;
            else if(sumi > target) r--;
            else if(sumi < target) l++;
        }
        for(int i = 0; i < n; i++){
            if(temp[i] == nums[l]) ans.push_back(i);
            else if(temp[i] == nums[r]) ans.push_back(i);
        }
        return ans;
    }
};