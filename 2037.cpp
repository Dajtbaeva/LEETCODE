2037. Minimum Number of Moves to Seat Everyone
Input: seats = [3,1,5], students = [2,7,4]
Output: 4
Explanation: The students are moved as follows:
- The first student is moved from from position 2 to position 1 using 1 move.
- The second student is moved from from position 7 to position 5 using 2 moves.
- The third student is moved from from position 4 to position 3 using 1 move.
In total, 1 + 2 + 1 = 4 moves were used.

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& st) {
        sort(seats.begin(), seats.end());
        sort(st.begin(), st.end());
        int n = seats.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += abs(seats[i] - st[i]);
        }
        return sum;   
    }
};