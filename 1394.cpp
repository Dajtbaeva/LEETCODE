1394. Find Lucky Integer in an Array
https://leetcode.com/problems/find-lucky-integer-in-an-array/
Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.

Return the largest lucky integer in the array. If there is no lucky integer return -1.

Input: arr = [1,2,2,3,3,3]
Output: 3
Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.

class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> m;
        vector<int> res;
        for(int i = 0; i < arr.size(); i++) m[arr[i]]++;
        vector<pair<int, int> > v(m.begin(), m.end());
        for(int i = 0; i < v.size(); i++){
            if(v[i].first == v[i].second) res.push_back(v[i].first);
        }
        if(res.empty()) return -1;
        else{
            sort(res.begin(), res.end(), greater<int>());
            return res[0];
        }
        
    }
};