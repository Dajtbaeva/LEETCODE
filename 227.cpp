227. Basic Calculator II
Input: s = "3+2*2"
Output: 7
условие ? command if true : command if false;
class Solution {
public:
    int calculate(string s) {
        stringstream ss(s + '+');
        int number; 
        char op; 
        char lastOp = '*';
        int result = 0, temp = 1, sign = 1;
        while(ss >> number >> op){
            temp = lastOp == '*' ?  temp * number : temp / number; 
            if(op == '+' || op == '-'){
                result += sign * temp;
                temp = 1;
                sign = op == '+' ? 1 : -1;
                lastOp = '*';
            }
            else lastOp = op;
        }   
        return result;       
    }
};