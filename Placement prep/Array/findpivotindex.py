# https://leetcode.com/problems/find-pivot-index/

class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        ls=0
        rs=sum(nums)
        n=len(nums)
        for i in range(n):
            rs-=nums[i]
            if(ls==rs):
                return i
            ls+=nums[i]
        return -1