# https://leetcode.com/problems/move-zeroes/submissions/

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i=0
        j=1
        while j< len(nums):
            if nums[i]==0 and nums[j]!=0:
                swap = nums[i]
                nums[i]= nums[j]
                nums[j]=swap
                i += 1
            elif nums[i]!=0:
                i += 1
            j += 1

        