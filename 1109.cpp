// 1109. Corporate Flight Bookings
// https://leetcode.com/problems/corporate-flight-bookings/
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
Input: bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
Output: [10,55,45,25,25]
Explanation:
Flight labels:        1   2   3   4   5
Booking 1 reserved:  10  10
Booking 2 reserved:      20  20
Booking 3 reserved:      25  25  25  25
Total seats:         10  55  45  25  25
Hence, answer = [10,55,45,25,25]

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> v(n + 2, 0); // 7:  0, 10, 45, -10, -20, 0, -25
        for(int i = 0; i < bookings.size(); ++i){ 
            v[bookings[i][0]] += bookings[i][2]; // v[1] += val
            v[bookings[i][1] + 1] += -bookings[i][2]; // v[3] -= val
        }
        
        vector<int> res;
        int counter = 0;
        for(int i = 1; i <= n; ++i){
            counter += v[i];
            res.push_back(counter);
        }
        
        return res;
    }
};
