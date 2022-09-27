649. Dota2 Senate
https://leetcode.com/problems/dota2-senate/
Input: senate = "RDD"
Output: "Dire"
Explanation: 
The first senator comes from Radiant and he can just ban the next senator's right in round 1. 
And the second senator can't exercise any rights anymore since his right has been banned. 
And the third senator comes from Dire and he can ban the first senator's right in round 1. 
And in round 2, the third senator can just announce the victory since he is the only guy in the senate who can vote.
'
class Solution {
public:
    string predictPartyVictory(string str) {
        queue<int> r, d;
        int n = str.size();
        for(int i = 0; i < str.size(); i++){
            if(str[i] == 'R') r.push(i);
            else if(str[i] == 'D') d.push(i);
        }
        while(!r.empty() && !d.empty()){
            if(r.front() < d.front()){
                d.pop();
                int a = r.front() + n;
                r.pop();
                r.push(a);
            }else if(d.front() < r.front()){
                r.pop();
                int a = d.front() + n;
                d.pop();
                d.push(a);
            }
        }
        if(r.empty()) return "Dire";
        else return "Radiant";
    }
};