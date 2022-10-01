91. Decode Ways
https://leetcode.com/problems/decode-ways/
A message containing letters from A-Z can be encoded into numbers using the following mapping:

'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).


class Solution {
public:
    int solve(string s, vector <int> &dp)
    {
        int n = s.length();
		
		// If length is zero then we got one way to decode the string so return 1
        if(n == 0)
            return 1;
			
		// If the starting chracter of the string is zero then the possible ways to decode are zero so return 0
        else if(s[0] == '0')
            return 0;
			
		// if we already solve this string then return the stored value (memoized value)
        else if(dp[n] != -1)
            return dp[n];
        
        int a = 0, b = 0;
		//Take only the starting character of string and call recursive for the rest of string
        a = solve(s.substr(1), dp);
		
		//Take two character of string if it is possible (length of string should be atleast 2 and the string must be between 0 to 26) and call recursive for the rest of the string
        if( (n > 1) && ( (s[0] == '1') || (s[0] == '2' && s[1] <= '6')))
            b = solve(s.substr(2), dp);
        
		//Store the solve value of the string for further use
        dp[n] = a+b;
        return dp[n];
    }
	int numDecodings(string s) 
    {
        int n = s.length();
        vector <int> dp(n+1, -1);
        return solve(s, dp);
    }
};


class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        dp[0] = s[0] == '0' ? 0 : 1;
        int prev = s[0] - '0';
        
        for(int i = 1; i < n; i++) {
            if (s[i] != '0') 
                dp[i] += dp[i - 1];
            
            if (prev == 1 || (prev == 2 && s[i] - '0' <= 6))
                dp[i] += i == 1 ? 1 : dp[i - 2];
            
            prev = s[i] - '0';
        }
        
        return dp[n - 1];
    }
};
