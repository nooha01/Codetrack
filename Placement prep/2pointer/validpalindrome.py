# https://leetcode.com/problems/valid-palindrome/

class Solution:
    def isPalindrome(self, s: str) -> bool:
        length = len(s)
        string = ""
        for i in range(0,length):
            if s[i].isalnum()==True:
                string += s[i]
        string=string.lower()
        rev = string[::-1]
        if(rev==string):
            return True
        else:
            return False