1578. Minimum Time to Make Rope Colorful
https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
Input: colors = "aabaa", neededTime = [1,2,3,4,1]
Output: 2
Explanation: Bob will remove the ballons at indices 0 and 4. Each ballon takes 1 second to remove.
There are no longer two consecutive balloons of the same color. Total time = 1 + 1 = 2.


class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost = 0;
        for(int i = 0; i < colors.size() - 1; i++){
            if(colors[i] == colors[i + 1]){
                if(neededTime[i] > neededTime[i + 1]){
                    cost += neededTime[i + 1];
                    neededTime[i + 1] = neededTime[i];
                } else cost += neededTime[i];
            }
        }
        return cost;
    }
};



class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        // Initalize two pointers i, j.
        int totalTime = 0;
        int i = 0, j = 0;
        
        while (i < neededTime.size() && j < neededTime.size()) {
            int currTotal = 0, currMax = 0;
            
            // Find all the balloons having the same color as the 
            // balloon indexed at i, record the total removal time 
            // and the maximum removal time.
            while (j < neededTime.size() && colors[i] == colors[j]) {
                currTotal += neededTime[j];
                currMax = max(currMax, neededTime[j]);
                j++;
            }
            
            // Once we reach the end of the current group, add the cost of 
            // this group to total_time, and reset two pointers.
            totalTime += currTotal - currMax;
            i = j;
        }
        return totalTime;
    }
};