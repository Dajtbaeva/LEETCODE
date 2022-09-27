1770. Maximum Score from Performing Multiplication Operations
https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/

class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int res = 0;
        deque<int> dq;
        // deque<int> dq(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) dq.push_back(nums[i]);
        for(int i = 0; i < multipliers.size(); i++){
            int a = abs(dq.front()) - 1 + abs(multipliers[i]);
            int b = abs(dq.back()) - 1 + abs(multipliers[i]);
            if(a < b)
            if(abs(a) >= abs(b)){
                res += a;
                dq.pop_front();
            }else{
                res += b;
                dq.pop_back();
            }
        }
        return res;
    }
};