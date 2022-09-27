451. Sort Characters By Frequency
https://leetcode.com/problems/sort-characters-by-frequency/
Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.

class Solution {
public:
    static bool comp(pair<char, int> &p1, pair<char, int> &p2){
        return p1.second > p2.second;
    }
    string frequencySort(string s) {
        map<char, int> m;
        for(int i = 0; i < s.size(); i++) m[s[i]]++;
        vector<pair<char, int> > v(m.begin(), m.end());
        sort(v.begin(), v.end(), comp);
        string res;
        for(int i = 0; i < v.size(); i++){
            while(v[i].second--){
                res += v[i].first;
            }
        } 
        return res;
    }
};