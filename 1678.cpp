1678. Goal Parser Interpretation
Input: command = "G()()()()(al)"
Output: "Gooooal"

class Solution {
public:
    string interpret(string command) {
        string t = "";
        for(int i = 0; i < command.size(); i++){
            if(command[i] == '('){
                if(command[i + 1] == ')') t += 'o';
                else t += "al";
            }
            else if(command[i] == 'G') t += command[i];
        }
        return t;
    }
};