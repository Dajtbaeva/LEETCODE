2194. Cells in a Range on an Excel Sheet

Input: s = "K1:L2"
Output: ["K1","K2","L1","L2"]
Explanation:
The above diagram shows the cells which should be present in the list.
The red arrows denote the order in which the cells should be presented.

Input: s = "A1:F1"
Output: ["A1","B1","C1","D1","E1","F1"]

class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string>boxes;
		for(int i = s[0] ; i<= s[3];i++){
			for(int j = s[1]; j<= s[4];j++){
				string temp = "";
				temp.push_back(i);
				temp.push_back(j);
				boxes.push_back(temp);
			}
		}
		return boxes;
    }
};