856. Score of Parentheses
Given a balanced parentheses string s, return the score of the string.

The score of a balanced parentheses string is based on the following rule:

"()" has score 1.
AB has score A + B, where A and B are balanced parentheses strings.
(A) has score 2 * A, where A is a balanced parentheses string.

class Solution {
public:
    int scoreOfParentheses(string s) {
        int depth = 0, res = 0;
        char prev = '(';
        for (const char &ch: s) {
            if (ch == '(')
                depth++;
            else {
                depth--;
                if (prev == '(')
                    res += pow(2, depth);
            }
            prev = ch;
        }
        return res;
    }
};