// Longest Common Prefix
// If there is no common prefix, return an empty string "".

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        res = min(strs, key=len)
        ans = ''
        for i in range(len(res)):
            if set(res[i]) == {sign[i] for sign in strs}:
                ans += res[i]
            else:
                break
        return ans

 