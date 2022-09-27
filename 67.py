# Given two binary strings a and b, return their sum as a binary string.
# Input: a = "1010", b = "1011"
# Output: "10101"

class Solution:
    def addBinary(self, a: str, b: str) -> str:
        return bin((int(a,2)+int(b,2)))[2:]
