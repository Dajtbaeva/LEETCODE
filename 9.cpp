// Palindrome Number https://www.code-recipe.com/post/palindrome-number
class Solution {
public:
    bool isPalindrome(int x) {
        vector<char> v1, v2;
        if(x == 0) return true;
        else if(x < 0 || x % 10 == 0) return false;
        else{
            while(x != 0){
                v1.push_back(char((x % 10) + 48));
                x /= 10;
            }
            v2 = v1;
            reverse(v2.begin(), v2.end());
            if(v1 == v2) return true;
            else return false;
        }
    }
};
