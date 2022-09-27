1598. Crawler Log Folder
Input: logs = ["d1/","d2/","../","d21/","./"]
Output: 2
Explanation: Use this change folder operation "../" 2 times and go back to the main folder.

class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> s;
        for(int i = 0; i < logs.size(); i++){
            if(logs[i] == "../"){
                if(!s.empty()) s.pop();
            } 
            else if(logs[i] != "./") s.push(logs[i]);
        }
        return s.size();
    }
};