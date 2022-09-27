771. Jewels and Stones
Input: jewels = "aA", stones = "aAAbbbb"
Output: 3

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int res = 0;
        for(int i = 0; i < jewels.size(); i++){
            for(int j = 0; j < stones.size(); j++){
                if(jewels[i] == stones[j]) res++;
            }
        }
        return res;
    }
};