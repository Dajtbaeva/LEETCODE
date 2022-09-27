// Plus One
// Input: digits = [1,2,3]
// Output: [1,2,4]
// Explanation: The array represents the integer 123.
// Incrementing by one gives 123 + 1 = 124.
// Thus, the result should be [1,2,4].

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int ans = 0;
        vector<int> res;
        for(int i = 0; i < digits.size(); i++){
            ans += digits[i] * pow(10, digits.size() - i - 1);
        }
        ans += 1;
        while(ans > 0){
            res.insert(res.begin(), 1, ans % 10);
            ans /= 10;
        }
        return res;
    }
};

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        return [int(n) for n in str((int("".join([str(i) for i in digits]))) + 1)]

