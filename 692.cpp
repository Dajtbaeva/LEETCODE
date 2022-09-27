692. Top K Frequent Words
https://leetcode.com/problems/top-k-frequent-words/
Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.

class Solution {
public:
    static bool comp(pair<string, int> &p1, pair<string, int> &p2){
        if(p1.second == p2.second) return p1.first < p2.first;
        return p1.second > p2.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m;
        vector<string> res;
        for(int i = 0; i < words.size(); i++) m[words[i]]++;
        vector<pair<string, int> > v(m.begin(), m.end());
        sort(v.begin(), v.end(), comp);
        for(int i = 0; i < k; i++) res.push_back(v[i].first);
        return res;
    }
};  