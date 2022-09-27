2103. Rings and Rods
Input: rings = "B0B6G0R6R0R6G9"
Output: 1
Explanation: 
- The rod labeled 0 holds 3 rings with all colors: red, green, and blue.
- The rod labeled 6 holds 3 rings, but it only has red and blue.
- The rod labeled 9 holds only a green ring.
Thus, the number of rods with all three colors is 1.

class Solution {
public:
    int countPoints(string rings) {
        int res = 0;
        map<char, set<char> > m;
        for(int i = 0; i < rings.size(); i+= 2){
            m[rings[i + 1]].insert(rings[i]);
        }
        map<char, set<char> > :: iterator it;
        for(it = m.begin(); it != m.end(); it++){
            if((*it).second.size() == 3) res++;
        } 
        return res;
    }
};  