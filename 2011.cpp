2011. Final Value of Variable After Performing Operations

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res = 0;
        for(int i = 0; i < operations.size(); i++){
            if(operations[i] == "++X" || operations[i] == "X++") res += 1;
            else res -= 1;
        }
        return res;
    }
};