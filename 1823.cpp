1823. Find the Winner of the Circular Game
https://leetcode.com/problems/find-the-winner-of-the-circular-game/
Input: n = 5, k = 2
Output: 3
Explanation: Here are the steps of the game:
1) Start at friend 1.
2) Count 2 friends clockwise, which are friends 1 and 2.
3) Friend 2 leaves the circle. Next start is friend 3.
4) Count 2 friends clockwise, which are friends 3 and 4.
5) Friend 4 leaves the circle. Next start is friend 5.
6) Count 2 friends clockwise, which are friends 5 and 1.
7) Friend 1 leaves the circle. Next start is friend 3.
8) Count 2 friends clockwise, which are friends 3 and 5.
9) Friend 5 leaves the circle. Only friend 3 is left, so they are the winner.
push_back
push_front
back
pop_back
class Solution {
public:
    int findTheWinner(int n, int k) {
        deque<int> d;
        for(int i=n;i>=1;i--){ 
            d.push_back(i);
        }
        
        while(d.size()!=1){
            for(int i=1;i<k;i++){
                d.push_front(d.back());
                d.pop_back();
            }
            d.pop_back();
        }
    return d.back();}
};
