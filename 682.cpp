682. Baseball Game
Input: ops = ["5","2","C","D","+"]
Output: 30
Explanation:
"5" - Add 5 to the record, record is now [5].
"2" - Add 2 to the record, record is now [5, 2].
"C" - Invalidate and remove the previous score, record is now [5].
"D" - Add 2 * 5 = 10 to the record, record is now [5, 10].
"+" - Add 5 + 10 = 15 to the record, record is now [5, 10, 15].
The total sum is 5 + 10 + 15 = 30.

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        for(int i = 0; i < ops.size(); i++){
            if(ops[i] == "C") s.pop();
            else if(ops[i] == "D"){
                int a = s.top();
                s.push(2 * a);
            }
            else if(ops[i] == "+"){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.push(a);
                s.push(a + b);
            }else s.push(stoi(ops[i]));
        }
        int res = 0;
        while(!s.empty()){
            res += s.top();
            s.pop();
        }
        return res;
    }
};