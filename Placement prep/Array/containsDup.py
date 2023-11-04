# https://leetcode.com/problems/contains-duplicate/

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        n = len(nums)
        for i in range(n-1):
            for j in range(i+1, n):
                if (nums[i]==nums[j]):
                   return True
        return False
    
#above code exceeds time 

class Solutionoptimised:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return len(set(nums))!=len(nums)
