1304. Find N Unique Integers Sum up to Zero
Given an integer n, return any array containing n unique integers such that they add up to 0.

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        if(n % 2 != 0) res.push_back(0);
        for (int i = 0; i < n/2; i++){
            res.push_back(i+1);
            res.insert(res.begin(), (i+1)*-1);
        }
        
        return res;  
    }
};