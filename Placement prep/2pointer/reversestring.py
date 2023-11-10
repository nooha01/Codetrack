# https://leetcode.com/problems/reverse-string/

class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        l,r = 0, len(s)-1
        while l<=r:
            temp = s[l]
            s[l] = s[r]
            s[r] = temp
            l = l+1
            r = r-1
        return s
    
 
 # alternate solution
 
def reverseString(self, s: List[str]) -> None:
    """
    Do not return anything, modify s in-place instead.
    """
    l = 0
    r = len(s) - 1
    while l < r:
        s[l],s[r] = s[r],s[l]
        l += 1
        r -= 1
